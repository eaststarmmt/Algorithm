#include<cstdio>
#define MAX 500
using namespace std;

bool visited[MAX][MAX];
int map[MAX][MAX];
int N, M, cnt, picture, maxCnt;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void dfs(int r, int c) {
	visited[r][c] = true;	// 방문 처리
	cnt++;				// cnt 증가

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 0 && nc >= 0 && nr < N && nc < M && !visited[nr][nc] && map[nr][nc] == 1) {
			dfs(nr, nc);	// 방문 안했고 1이면 방문
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && map[i][j] == 1) {		// 방문 안했고 1인곳이 있으면 그림 한 개 있음
				dfs(i, j);
				picture++;							// 그림 카운팅
				maxCnt = cnt > maxCnt ? cnt : maxCnt;	// 가장 넓은 그림 갱신
				cnt = 0;		// cnt 초기화
			}
		}
	}

	printf("%d\n%d\n", picture, maxCnt);
}