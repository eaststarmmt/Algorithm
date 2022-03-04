#include<stdio.h>
#define MAX 100

int main() {

	int N;
	scanf("%d", &N);
	int map[MAX][MAX];
	long long dp[MAX][MAX] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1) continue;		// 이거 없으면 마지막에 도착지점에서 본인 위치만 두번 더해버림
			if (i + map[i][j] < N)						// 점프해서 밖으로 튕귀지 않는 경우만 
				dp[i + map[i][j]][j] += dp[i][j];		// dp에 현재 지점까지 온 경우의 수를 계속 더함.
			if (j + map[i][j] < N)						// 들리지 않는 경우는 계속 0으로 있음
				dp[i][j + map[i][j]] += dp[i][j];

		}
	}
	printf("%lld\n", dp[N - 1][N - 1]);
}