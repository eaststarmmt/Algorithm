#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
int visited[100004];
int previous[100004];

void bfs() {
	queue<int> Q;
	Q.push(N);

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();

		if (now == K) {
			return;
		}

		for (int next : {now + 1, now - 1, now * 2}) {
			if (next < 0 || next > 100000 || visited[next]) {
				continue;
			}

			visited[next] = visited[now] + 1;
			previous[next] = now;
			Q.push(next);
		}	// end of for next
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	bfs();
	vector<int> res;
	for (int i = K; i != N; i = previous[i]) {
		res.push_back(i);
	}
	res.push_back(N);
	cout << visited[K] << "\n";
	reverse(res.begin(), res.end());
	for (int x : res) {
		cout << x << ' ';
	}
	return 0;
}