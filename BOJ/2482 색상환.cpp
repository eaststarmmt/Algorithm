#include<cstdio>
#define MOD 1000000003
using namespace std;

int dp[1001][1001];	// dp[N][K] 의 형태

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;		// 0개 고르는 경우의 수는 무조건 1
		dp[i][1] = i;		// 1개 고르는 경우의 수는 N
	}

	for (int i = 4; i <= N; i++) {		// N이 3이하는 사이클이 발생해 2개이상 고를 수 없음
		for (int j = 2; j <= K; j++) {	// K가 0과 1인 경우는 위에서 이미 정의 내림
			dp[i][j] = (dp[i - 2][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;	// N -2개 중 K - 1 개 고른 경우와 N - 1 개 중 K개 만큼 고른 경우의 수를 더함
		}
	}
	printf("%d\n", dp[N][K]);
}