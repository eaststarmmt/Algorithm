#include <iostream>
#include <algorithm>
using namespace std;

int R, C, res;
char map[24][24];
int visited[30];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void dfs(int r = 1, int c = 1, int cnt = 1) {
	res = max(cnt, res);
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 1 || nr > R || nc < 1 || nc > C || visited[map[nr][nc] - 'A']) {
			continue;
		}
		visited[map[nr][nc] - 'A'] = 1;
		dfs(nr, nc, cnt + 1);
		visited[map[nr][nc] - 'A'] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}	// end of for j
	}	// end of for i
	visited[map[1][1] - 'A'] = 1;
	dfs();
	cout << res << "\n";
	return 0;
}