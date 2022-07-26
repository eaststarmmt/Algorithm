#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Info {
	int r, c, cnt;
};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int R, C, max_dis;
char map[54][54];
bool visited[54][54];

int bfs(int r, int c) {
	memset(visited, false, sizeof(visited));

	int ret = 0;

	visited[r][c] = true;
	queue<Info> Q;
	Q.push({ r, c, 0 });

	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		int cnt = Q.front().cnt;

		Q.pop();

		ret = cnt > ret ? cnt : ret;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc] || map[nr][nc] == 'W') {
				continue;
			}

			Q.push({ nr, nc, cnt + 1 });
			visited[nr][nc] = true;
		}

	}	// end of while

	return ret;
}

int main() {
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %1c", &map[i][j]);
		}	// end of for j
	}	// end of for i

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'W') {
				continue;
			}
			int dis = bfs(i, j);
			max_dis = dis > max_dis ? dis : max_dis;
		}	// end of for j
	}	// end of for i

	printf("%d\n", max_dis);
	return 0;
}