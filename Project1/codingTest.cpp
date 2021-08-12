#include<stdio.h>
#define MAX 501
														// -1은 아직 방문하지 않은 곳, 0은 방문 했으나 아직 도착 경로 판정이 나지 않은 곳
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int map[MAX][MAX];
int dp[MAX][MAX];

int M, N;

int dfs(int r, int c) {
	if (r < 0 || c < 0 || r >= M || c >= N) return 0;	// 밖으로 튕긴 경우
	if (r == 0 && c == 0) return 1;						// 도착한 경우
	if (dp[r][c] != -1) return dp[r][c];				// 이미 확인한 경우 그 만큼 더해주면 됨

	dp[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (map[nr][nc] > map[r][c]) {
			dp[r][c] += dfs(nr, nc);				// 이전 경로를 확인하고 현재 경로에 값을 더해줌
		}
	}
	return dp[r][c];

}

int main() {


	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}

	printf("%d\n", dfs(M - 1, N - 1));

}