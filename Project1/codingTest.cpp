#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	unordered_map<string, int> notListen;
	for (int i = 0; i < N; i++) {	// 듣도 못한인간 맵에 저장
		string s;
		cin >> s;
		notListen[s] = 1;
	}
	vector<string> result;
	for (int j = 0; j < M; j++) {	//보도 못한인간이 맵에 없으면 벡터에 넣기
		string s;
		cin >> s;
		if (notListen.find(s) != notListen.end())
			result.push_back(s);
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (auto i : result) {
		cout << i << endl;
	}
}