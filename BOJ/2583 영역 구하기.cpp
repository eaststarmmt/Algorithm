#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int map[105][105];
bool visited[105][105];
int M, N, K;
int cnt;

int dfs(int r, int c) {
	visited[r][c] = true;
	int res = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc]) {
			continue;
		}
		if (map[nr][nc] == 1) {
			continue;
		}
		res += dfs(nr, nc);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		for (int r = r1; r < r2; r++) {
			for (int c = c1; c < c2; c++) {
				map[r][c] = 1;
			}
		}
	}
	vector<int> res;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && map[i][j] == 0) {
				res.push_back(dfs(i, j));
			}
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int i : res) {
		cout << i << ' ';
	}
	return 0;
}