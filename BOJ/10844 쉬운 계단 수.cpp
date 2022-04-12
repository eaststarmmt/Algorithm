#include<stdio.h>

int dp[101][10];		// 100 자리수 까지 볼 것이므로 크기를 101로 앞에는 자리수, 뒤에는 끝자리

int main() {
	int n;
	scanf("%d", &n);
	long long cnt = 0;			// 나머지를 구해도 너무 커서 long long 사용

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][1] % 1000000000;		// 끝자리가 0인 경우 앞에 끝자리가 1인 경우의 수만큼 나옴
			else if (j == 9)
				dp[i][j] = dp[i - 1][8] % 1000000000;		// 끝자리가 9인 경우 앞에 끝자리가 1인 경우의 수만큼 나옴
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;	// ex) dp[3][2] = dp[2][1] + dp[2][3]
			
		}
	}
	for (int i = 0; i <= 9; i++) {
		cnt += dp[n][i];
	}
	printf("%lld", cnt % 1000000000);
}