#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int wine[10001];
	int dp[10001];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &wine[i]);
	}
	dp[0] = wine[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= n; i++) {	// 세번 연속 못먹으므로 최소한 이전에 세개가 확보 되어있어야 됨. 이런 경우 0번째 값을 0으로 만들어서 식을 확보 가능
		dp[i] = max(max(dp[i - 2] + wine[i], dp[i - 1]), dp[i - 3] + wine[i - 1] + wine[i]);	
	}

	printf("%d\n", dp[n]);

}