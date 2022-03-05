#include<iostream>
#include<unordered_map>
#include<queue>
#define endl "\n"
using namespace std;
class Info {
public:
	int x, cnt;
	Info(int x, int cnt) {
		this->x = x;
		this->cnt = cnt;
	}	
};
int N, M;
unordered_map<int, int> ladder;
bool visited[101];
int res;
void bfs(int start) {
	queue<Info> Q;
	Q.push(Info(start, 0));
	visited[start] = true;
	while (!Q.empty()) {
		int x = Q.front().x;
		int cnt = Q.front().cnt;
		if (x > 100) continue;	// 100을 넘어가면 이동 불가. 그냥 버리기
		else if (x == 100) {	// 100 도착하면 처음 도착이 최소 거리이므로 저장 후 리턴
			res = cnt;
			return;
		}
		Q.pop();
		for (int i = 1; i <= 6; i++) {
			if (!visited[x + i]) {
				visited[x + i] = true;
				if (ladder.find(x + i) != ladder.end()) {	// 사다리나 뱀에 간 경우
					Q.push(Info(ladder[x + i], cnt + 1));	// 바로 그 위치로 이동해서 방문 처리 후 큐에 넣기
					visited[ladder[x + i]] = true;
				}
				else {
					Q.push(Info(x + i, cnt + 1));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}	// 사다리 입력

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		ladder[u] = v;
	}	// 뱀 입력

	bfs(1);
	cout << res << endl;
}