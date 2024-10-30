#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <iostream>
using namespace std;

pair<int, int> parent[54][54];
string a[54][54];

void print() {
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			int r = parent[i][j].first;
			int c = parent[i][j].second;
			cout << a[r][c] << ' ';
		}
		cout << endl;
	}
	cout << "----------------------------------------------------------" << endl;
}

vector<string> get_sql(string s) {
	stringstream ss(s);
	vector<string> res;
	string temp;

	while (ss >> temp) {
		res.push_back(temp);
	}   // end of while

	return res;
}

pair<int, int> find_parent(int r, int c) {
	pair<int, int> p = parent[r][c];
	if (p.first == r && p.second == c) return p;
	return parent[r][c] = find_parent(p.first, p.second);
}

void union_parent(pair<int, int> p1, pair<int, int> p2) {
	p1 = find_parent(p1.first, p1.second);
	p2 = find_parent(p2.first, p2.second);

	parent[p2.first][p2.second] = p1;
}

set<pair<int, int>> find_value(string value) {
	set<pair<int, int>> res;
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			pair<int, int> p = find_parent(i, j);
			string s = a[p.first][p.second];
			if (s != value) continue;

			res.insert(p);
		}
	}

	return res;
}

void update(vector<string> sql) {
	if (sql.size() == 4) {   // 특정 위치 값 바꾸는 경우
		int r = stoi(sql[1]);
		int c = stoi(sql[2]);
		pair<int, int> p = find_parent(r, c);
		a[p.first][p.second] = sql[3];
		return;
	}

	// value 두개 주어지는 경우
	set<pair<int, int>> set = find_value(sql[1]);   // value1인 셀 찾기

	// value2로 저장
	for (auto i : set) {
		a[i.first][i.second] = sql[2];
	}
}

void merge(vector<string> sql) {
	int r1 = stoi(sql[1]);
	int c1 = stoi(sql[2]);
	int r2 = stoi(sql[3]);
	int c2 = stoi(sql[4]);
	pair<int, int> p1 = find_parent(r1, c1);
	pair<int, int> p2 = find_parent(r2, c2);

	if (p1 == p2) return;  // 이미 병합 된 셀이면 무시
	if (r1 == r2 && c1 == c2) return;    // 같은 셀인 경우 무시

	string s;

	if (!a[p1.first][p1.second].empty() && !a[p2.first][p2.second].empty()) {
		s = a[p1.first][p1.second];
	}
	else if (a[p1.first][p1.second].empty()) {
		s = a[p2.first][p2.second];
	}
	else if (a[p2.first][p2.second].empty()) {
		s = a[p1.first][p1.second];
	}

	a[r1][c1] = a[r2][c2] = "";

	union_parent({ r1, c1 }, { r2, c2 });
	pair<int, int> p = find_parent(r1, c1);
	a[p.first][p.second] = s;
}

vector<pair<int, int>> find_child(pair<int, int> target) {
	vector<pair<int, int>> res;
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			pair<int, int> p = find_parent(i, j);
			if (p == target) res.push_back({ i, j });
		}   // end of for j
	}   // end of for i
	return res;
}

void unmerge(vector<string> sql) {
	int r = stoi(sql[1]);
	int c = stoi(sql[2]);
	pair<int, int> p = find_parent(r, c);
	string s = a[p.first][p.second];

	vector<pair<int, int>> v = find_child({ p.first, p.second });

	// 부모 자기 자신으로 변경
	for (pair<int, int> p : v) {
		parent[p.first][p.second] = p;
		a[p.first][p.second] = "";
	}   // end of for

	// 원래 가지고 있던 값 r, c에 넣기
	a[r][c] = s;
}

string print(vector<string> sql) {
	pair<int, int> p = find_parent(stoi(sql[1]), stoi(sql[2]));
	return a[p.first][p.second].empty() ? "EMPTY" : a[p.first][p.second];
}

vector<string> solution(vector<string> commands) {
	vector<string> answer;

	// 자기 자신을 부모로 설정
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			parent[i][j] = { i, j };
		}
	}
	//print();
	for (string s : commands) {
		vector<string> sql = get_sql(s);
		if (sql[0] == "UPDATE") update(sql);
		else if (sql[0] == "MERGE") merge(sql);
		else if (sql[0] == "UNMERGE") unmerge(sql);
		else answer.push_back(print(sql));

		//print();
	}   // end of for

	return answer;
}