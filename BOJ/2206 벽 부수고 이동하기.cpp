#include<cstdio>
#include<queue>
using namespace std;

struct Pos {
	int r, c, wall, cnt;
};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int R, C;
bool visited[1000][1000][2];
int map[1000][1000];

int bfs() {
	queue<Pos> Q;
	Q.push({ 0, 0, 0, 1});
	visited[0][0][0] = true;
	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		int wall = Q.front().wall;	// 벽 부순 횟수
		int cnt = Q.front().cnt;	// 이동 횟수
		Q.pop();
		if (r == R - 1 && c == C - 1) 
			return cnt;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
			if (map[nr][nc] == 0 && !visited[nr][nc][wall]) {	// 벽이 아니면서 방문하지 않은 경우
				Q.push({ nr, nc, wall, cnt + 1 });
				visited[nr][nc][wall] = true;
			}
			else if (map[nr][nc] == 1 && wall == 0 && !visited[nr][nc][1]) {	// 벽인데 아직 벽을 안 부순 경우
				Q.push({ nr, nc, 1, cnt + 1 });
				visited[nr][nc][1] = true;
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %1d", &map[i][j]);
		}
	}	// end of map
	printf("%d\n", bfs());
}