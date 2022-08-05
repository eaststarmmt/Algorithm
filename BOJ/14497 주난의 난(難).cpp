#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
char map[304][304];
bool visited[304][304];
int R, C;
int r1, c1, r2, c2;
int res, cnt;

void bfs() {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> Q;
	Q.push({ r1, c1 });
	visited[r1][c1] = true;
	cnt++;
	vector<pair<int, int>> fri;

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		if (r == r2 && c == c2) {
			res = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 1 || nr > R || nc < 1 || nc > C || visited[nr][nc]) {
				continue;
			}

			if (map[nr][nc] == '1') {
				fri.push_back({ nr, nc });
			}
			else {
				Q.push({ nr, nc });
			}
			visited[nr][nc] = true;
		}	// end of for
	}	// end of while

	for (pair<int, int> pos : fri) {
		map[pos.first][pos.second] = '0';
	}
}

int main() {
	scanf("%d %d", &R, &C);
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf(" %1c", &map[i][j]);
		}	// end of for j
	}	// end of for i

	while (!res) {
		bfs();
	}

	printf("%d\n", res);
	return 0;
}