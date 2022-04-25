#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, vector<int>> db;  // info를 저장할 db
vector<int> answer;
void setDb(string info) {
	stringstream stream(info);
	string temp[5];

	for (int i = 0; i < 5; i++) {    // temp에 공백기준으로 나눠서 저장
		stream >> temp[i];
	}   // end of for

	for (int i = 0; i < 16; i++) {
		string s;
		// 비트마스킹을 이용해서 정보를 넣지 않는(-) 경우와 넣는 경우 모든 경우의 수를 넣어줌
		// 이렇게 중복값을 넣으면 query에서 검색할 때 따로 찾지 않고 바로 검색 가능(메모리는 낭비 됨)
		// 0000 이면 ---- 0001 이면 ---pizza 이런 식으로 맵의 key값을 저장
		for (int j = 0; j < 4; j++) {
			s += i & (1 << j) ? temp[j] : "-";
		}   // end of for j
		db[s].push_back(stoi(temp[4]));
	}   // end of for i

}   // end of setDb
/*
	DB 안에 key에 해당하는 점수들을 sort 해줌
	lower_bound를 이용하기 위함
*/
void sortDB() {
	for (auto& i : db) {     // for each는 값을 변경하지 않기 때문에 주소로 직접 접근해야 됨
		sort(i.second.begin(), i.second.end());
	}
}   // end of sortDB

pair<string, int> getQuery(string data) {
	string query[4];
	stringstream stream(data);
	string score;
	// 중간에 and 소모하기 위해 score에 넣고 마지막에 점수로 덮기
	stream >> query[0] >> score >> query[1] >> score >> query[2] >> score >> query[3] >> score;
	string info;
	for (int i = 0; i < 4; i++) {
		info += query[i];
	}
	return make_pair(info, stoi(score));
}

vector<int> solution(vector<string> info, vector<string> query) {
	for (int i = 0; i < info.size(); i++) {
		setDb(info[i]);
	}   // end of for

	sortDB();

	for (int i = 0; i < query.size(); i++) {
		pair<string, int> quer = getQuery(query[i]);
		vector<int> scoreList = db[quer.first];
		// lower_bound가 크거나 같은 값의 첫번째 인덱스를 나타내 주기 때문에 끝에서 빼주면 조건에 맞는 개수가 됨
		int cnt = scoreList.end() - lower_bound(scoreList.begin(), scoreList.end(), quer.second);
		answer.push_back(cnt);
	}
	return answer;
}