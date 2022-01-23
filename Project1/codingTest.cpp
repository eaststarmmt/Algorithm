#include<cstdio>
#include<algorithm>
using namespace std;

int map[1001][1001];	
int dp[1001][1001];
int main() {
	int R, C;
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &map[i][j]);
		}
	}	// end of input

	for (int i = 1; i <= R; i++) {		// 0으로 초기화 되어있기 때문에 초기화 필요 없음
		for (int j = 1; j <= C; j++) {	// 왼쪽, 왼쪽 대각선 위, 위쪽 이렇게 세군대의 최대값 + 자기 자신으로 갱신
			dp[i][j] = map[i][j] + max(dp[i][j - 1], max(dp[i - 1][j - 1], dp[i - 1][j]));
		}
	}

	printf("%d\n", dp[R][C]);
}