#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[301];	// 계단의 점수를 계속 기록할 배열과 dp를 계산할 배열을 따로 구분 해야됨
int sta[301];	// 안그러면 계산이 두번씩 되기 때문에 값이 존나 커짐
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sta[i]);
	}
	dp[1] = sta[1];
	dp[2] = sta[1] + sta[2];
	dp[3] = max(sta[1] + sta[3], sta[2] + sta[3]);	// 최대한 관계 찾으려고 공책에 써봐야 됨
	for (int i = 4; i <= n; i++) {		// 6번쯤 가면 i - 3 까지의 최대값 + i - 1vs i - 2의 최대값중 큰 놈 고르는 거란걸 알 수 있음.
		dp[i] = max(dp[i - 2], dp[i -3] + sta[i - 1]) + sta[i];
	}
	printf("%d\n", dp[n]);
}