#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<string>
#include<unordered_map>
#define endl "\n"
using namespace std;

int R, C, start;
int hamming[100001];
int graph[100001];
unordered_map<int, int> path;

vector<int> findPath(int end) {
	vector<int> res;
	while (true) {
		res.push_back(end);
		if (end == 1) break;
		else if (end == -1) {
			vector<int> null;
			return null;
		}
		end = graph[end];
	}
	return res;
}

void bfs() {
	queue<int> Q;
	Q.push(start);
	graph[1] = 1;
	
	while (!Q.empty()) {
		int x = Q.front();	// 값
		int idx = path[x];	// 인덱스
		Q.pop();
		for (int i = 0; i < C; i++) {
			int next = x ^ (1 << i);
			if (path.find(next) != path.end()) {	// 해밍거리가 1인거 찾기 xor로 자리 수 별로 하나만 다른애 찾을 수 있음
				int nextIdx = path[next];
				if (graph[nextIdx] == -1) { // 아직 방문 안했으면
					Q.push(next);			// 큐에 값 넣기
					graph[nextIdx] = idx;	// 어디서 방문했는지 체크. 값 뽑아내야 되기 때문에
				}
			}
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string s;
		cin >> s;
		for (int j = C - 1; j >= 0; j--) {
			if (s[j] == '1')
				hamming[i] += (1 << C - j - 1);
		}
		path[hamming[i]] = i;	// 값을 가지고 번호를 찾아야 됨
		if (i == 1) start = hamming[i];
	}	// end of hamming 
	
	memset(graph, -1, sizeof(graph));
	bfs();
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		vector<int> res = findPath(x);
		if (res.size() == 0) cout << -1;
		else {
			for (int i = res.size() - 1; i >= 0; i--) {
				cout << res[i] << ' ';
			}
		}
		cout << endl;
	}
}