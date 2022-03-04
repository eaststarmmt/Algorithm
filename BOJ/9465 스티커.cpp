#include<stdio.h>
#include<algorithm>
using namespace std;

int sticker[2][100001];
int dp[2][100001];

int main() {
	int T;
	scanf("%d", &T);

	for (int test = 1; test <= T; test++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &sticker[i][j]);
				dp[i][j] = 0;
			}
		}
		
		dp[0][0] = sticker[0][0];	// dp[0][0]은 00에 스티커를 무조건 떼는 경우
		dp[1][0] = sticker[1][0];
		dp[0][1] = dp[1][0] + sticker[0][1];
		dp[1][1] = dp[0][0] + sticker[1][1];

		for (int i = 2; i < n; i++) {
			dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);		// 대각선 쪽에 스티커를 떼는 경우와 그 바로 전 스티커를 떼는경우 중 큰  경우를 현재 스티커 점수와 같이 더해줌
			dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		printf("%d\n", max(dp[0][n - 1], dp[1][n - 1]));		// 위 아래중에 더 큰 값 출력
	}
}