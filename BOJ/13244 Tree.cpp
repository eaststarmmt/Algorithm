#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int T;
int visited[1004];
vector<int> graph[1004];

void dfs(int x) {
	visited[x] = 1;
	for (int y : graph[x]) {
		if (visited[y]) continue;
		dfs(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= N; i++) {
			graph[i].clear();
		}	// end of for clear

		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;
			graph[A].push_back(B);
			graph[B].push_back(A);
		}	// end of for i

		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}
		}	// end of for i

		if (cnt == 1 && M == N - 1) {
			puts("tree");
		}
		else {
			puts("graph");
		}
	}	// end of while

	return 0;
}