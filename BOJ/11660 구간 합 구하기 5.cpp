#include<stdio.h>

int sum[1025][1025];
int map[1025][1025];

int main() {

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j ++) {
			scanf("%d", &map[i][j]);
		}
	}	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			
			sum[i][j] = map[i][j] - sum[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j];		// i,j 까지의 합을 구해둠. 중복으로 더해지는 부분은 제거
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]);	// 중복으로 뺀 부분 다시 더해줌
	}

}