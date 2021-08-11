#include<stdio.h>
#define MAX 501

int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, 1, -1, 0 };

int map[MAX][MAX];
int dp[MAX][MAX];


int main() {
	
	int M, N;
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 | ny < 0 | nx >= M | ny >= N)
					continue;
				if (map[i][j] > map[nx][ny]) {
					dp[nx][ny] += dp[i][j];
				}
				// Áö¿ö¾ß µÊ
				printf("\n");
				for (int a = 0; a < M; a++) {
					for (int b = 0; b < N; b++) {
						printf("%d ", dp[a][b]);
					}
					printf("\n");
				}

			}
		}
		printf("\n");
		for (int a = 0; a < M; a++) {
			for (int b = 0; b < N; b++) {
				printf("%d ", dp[a][b]);
			}
			printf("\n");
		}
	}
	printf("%d\n", dp[M - 1][N - 1]);

}