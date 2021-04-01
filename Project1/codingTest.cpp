#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int dp[502][502];	//dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);의 점화식에서 왼쪽과 오른쪽이 터지는 것을 방지하기 위해 502로 둠. 
int main() {		// 시작도 1부터 해야 됨
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int x;
			scanf("%d", &dp[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);	//삼각형 인덱스 관계 생각 잘해야됨.
		}														//위를 먼저 계산하고 밑으로 가야 됨. 그림때매 밑에서 보게 되는거 주의!!
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (result < dp[n][i]) 
			result = dp[n][i];
	}
	printf("%d\n", result);
}