#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int dist[100004];
int cnt[100004];

void bfs() {
	queue<int> Q;
	Q.push(N);
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int next : {now + 1, now - 1, now * 2}) {
			if (next < 0 || next > 100000) {
				continue;
			}
			if (dist[next] == 0) {	// 방문한 적이 없는 경우 큐에 넣고 방문
				Q.push(next);
				cnt[next] += cnt[now];
				dist[next] = dist[now] + 1;
			}
			else if (dist[next] == dist[now] + 1) {	// 최단경로 중복되는 경우 cnt만 표시
				cnt[next] += cnt[now];
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	if (N == K) {
		cout << 0 << "\n";
		cout << 1 << "\n";	// 안가는 것도 하나의 방법으로 치는듯.....
		return 0;
	}
	cnt[N] = 1;		// 처음부터 같은 위치는 위에서 종료 시켜서 예외 없음
	bfs();
	cout << dist[K] << "\n";
	cout << cnt[K] << "\n";
	return 0;
}