#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<queue>
#define endl "\n"
using namespace std;

set<string> visited;		// 기존의 단어가 들어왔는지 체크하기 위해 사용. set은 binary search tree 이므로 시간복잡도 O(logN)
string sortGame;			
int N, K;

int bfs() {
	string want = sortGame;		
	sort(want.begin(), want.end());		// 입력받은 단어를 sort해서 정답이 뭔지 찾아놓기
	queue<pair<string, int>> Q;
	Q.push({ sortGame, 0 });
	visited.insert(sortGame);			// visited에 현재 단어 저장

	while (!Q.empty()) {
		string s = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();

		if (s == want) return cnt;		// 정답이면 cnt 출력

		for (int i = 0; i <= N - K; i++) {
			string cut = s.substr(i, K);	// i부터 K개 잘라내기
			reverse(cut.begin(), cut.end());	// reverse 라이브러리 이용
			string check = s.substr(0, i);		// 0번째부터 i개 즉 cut에서 잘라내기 이전부분 잘라냄
			check += cut + s.substr(i + K);		// 뒤집은 cut과 cut 이후 부분 붙이기
				
			if (visited.find(check) == visited.end()) {		// visited 에 들어왔는지 확인
				Q.push({ check, cnt + 1 });			// 단어가 없었다면 Q에 넣기
				visited.insert(check);				// 현재 단어 visited에 등록
			}
		}
	}
	return -1;
}

int main() {
	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		char x;
		cin >> x;
		sortGame += x;
	}

	cout << bfs() << endl;
}