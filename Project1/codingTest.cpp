#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int map[100][100];
bool visited[100][100];
int cnt;
int H, W;
int preCnt;

void bfs() {
	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });
	visited[0][0] = true;
	
	int time = 0;
	while (true) {
		while (!Q.empty()) {
			int r = Q.front().first;
			int c = Q.front().second;

			Q.pop();

			if (map[r][c] == 1) {
				for (int i = 0; i < 4; i++) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					if (nr >= 0 && nr < H && nc >= 0 && nc < W && map[nr][nc] == 0) {
						cnt--;
						map[r][c] = 0;
						break;
					}
				}
			}

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc]) {
					Q.push({ nr, nc });
					visited[nr][nc] = true;
				}
			}
		}
		if (cnt == 0) {
			printf("%d\n", preCnt);
			printf("%d\n", time);
			return;
		}
		preCnt = cnt;
		time++;
		for (int i = 0; i < H; i++) {
			fill(visited[i], visited[i] + W + 1, false);
		}
	}
}

int main() {
	
	scanf("%d %d", &H, &W);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) cnt++;
		}
	}
	preCnt = cnt;

	bfs();
}