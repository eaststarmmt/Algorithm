#include<stdio.h>
#define MAX 501
														// -1�� ���� �湮���� ���� ��, 0�� �湮 ������ ���� ���� ��� ������ ���� ���� ��
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int map[MAX][MAX];
int dp[MAX][MAX];

int M, N;

int dfs(int r, int c) {
	if (r < 0 || c < 0 || r >= M || c >= N) return 0;	// ������ ƨ�� ���
	if (r == 0 && c == 0) return 1;						// ������ ���
	if (dp[r][c] != -1) return dp[r][c];				// �̹� Ȯ���� ��� �� ��ŭ �����ָ� ��

	dp[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (map[nr][nc] > map[r][c]) {
			dp[r][c] += dfs(nr, nc);				// ���� ��θ� Ȯ���ϰ� ���� ��ο� ���� ������
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