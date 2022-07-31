#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int R, C;
char map[1004][1004];
int jihoon_visited[1004][1004];
int fire_visited[1004][1004];
queue<pair<int, int>> Q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	fill(&fire_visited[0][0], &fire_visited[0][0] + 1004 * 1004, INF);
	int temp_r, temp_c;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'F') {
				Q.push({ i, j });
				fire_visited[i][j] = 1;
			}
			if (map[i][j] == 'J') {
				temp_r = i;
				temp_c = j;
				jihoon_visited[i][j] = 1;
			}
		}	// end of for j
	}	// end of for i

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
				continue;
			}
			if (fire_visited[nr][nc] != INF || map[nr][nc] == '#') {
				continue;
			}
			fire_visited[nr][nc] = fire_visited[r][c] + 1;
			Q.push({ nr, nc });
		}	// end of for
	}	// end of while fire

	int res = 0;
	Q.push({ temp_r, temp_c });

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		if (r == 0 || r == R - 1 || c == 0 || c == C - 1) {
			res = jihoon_visited[r][c];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
				continue;
			}
			if (jihoon_visited[nr][nc]) continue;
			if (map[nr][nc] == '#' || jihoon_visited[r][c] + 1 >= fire_visited[nr][nc]) {
				continue;
			}
			Q.push({ nr, nc });
			jihoon_visited[nr][nc] = jihoon_visited[r][c] + 1;

		}	// end of for

	}	// end of while jihoon

	if (res) {
		cout << res << "\n";
	}
	else {
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}