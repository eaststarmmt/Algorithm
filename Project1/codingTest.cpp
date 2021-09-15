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
	while (cnt > 0) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < H && nc < W) {
				if (map[nr][nc] == 0) {
					
				}
			}
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