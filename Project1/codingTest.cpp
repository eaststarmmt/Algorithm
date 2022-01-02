#include<cstdio>
#include<algorithm>
#define endl "\n"
using namespace std;

int dp[16];
int t[16];
int p[16];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}	// end of input

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		int nextTime = i + t[i];	// 지금 일 했을때 결과 나오는 시간
		int noWork = i + 1;		// 일 안했을때 경우 계산하기 위함

		if (nextTime <= N + 1) // N + 1이면 N 일까지 일 했다는 뜻임
			dp[nextTime] = dp[i] + p[i] > dp[nextTime] ? dp[i] + p[i] : dp[nextTime];
		else	// 인덱스 범위 넘어가는거 방지
			nextTime = 0;

		if (noWork <= N + 1)
			dp[noWork] = dp[i] > dp[noWork] ? dp[i] : dp[noWork];
		else
			noWork = 0;
		
		ans = max(ans, max(dp[noWork], dp[nextTime]));	// 지금까지 나온 것 중에 최대값 골라냄
	}
	printf("%d\n", ans);
}