#include <iostream>
#include <algorithm>
using namespace std;

char map[6][6];
int visited[6][6];
int R, C, K;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int dfs(int r, int c) {
	if (r == 0 && c == C - 1) {
		if (visited[r][c] == K) return 1;
		else return 0;
	}

	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc] || map[nr][nc] == 'T') {
			continue;
		}
		visited[nr][nc] = visited[r][c] + 1;
		cnt += dfs(nr, nc);
		visited[nr][nc] = 0;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}	// end of for j
	}	 // end of for i
	visited[R - 1][0] = 1;
	cout << dfs(R - 1, 0) << "\n";
	return 0;
}