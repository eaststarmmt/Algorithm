#include<stdio.h>
#define MAX 200 + 1

int main() {

	int n, k;
	scanf("%d %d", &n, &k);
	long long dp[MAX][MAX] = { 0 };

	for (int i = 0; i <= n; i++) {
		dp[i][1] = 1;
		dp[i][2] = i + 1;
	}

	for (int i = 3; i <= k; i++) {			
		for (int j = 0; j <= n; j++) {
			for(int z = 0; z <= j; z++) {						// ex> n = 20 k = 3 이라 가정했을 때 k = 2 로 0 ~ 20 까지의 숫자 + 20 ~ 0 을 더하는 방법
				dp[j][i] += (dp[j - z][i - 1]) % 1000000000;	// 즉 k = 2 로 0 ~ 20 까지의 숫자를 만드는 경우의 수를 다 더하면 됨
			}
		}
	}
	
	printf("%lld", dp[n][k] % 1000000000);
}