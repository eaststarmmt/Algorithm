#include<cstdio>
#include<algorithm>
#define MAX 100001
using namespace std;

int weight[101];
int value[MAX];
int dp[101][MAX];	// [물건의 번호][만들고자 하는 무게]

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}

	for (int i = 1; i <= N; i++) {	// 물건의 번호
		for (int j = 1; j <= K; j++) {	// 만들고자 하는 무게
			if (j >= weight[i])	// 만들고자 하는 무게가 현재 확인하는 물건의 무게보다 커야 담을 수 있음
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);	// 이전 물건까지 담아서 목표 무게를 만든 경우와 
							// 이전물건까지 담아서 만들고자 하는 무게 - 현재 물건의 무게의 가치에 현재 물건의 가치를 더한것중 큰 것 고르기

			else		// 목표 무게보다 현재 물건의 무게가 커서 어차피 담지 못하므로 이전 물건까지 확인했단 가치를 그대로 저장
				dp[i][j] = dp[i - 1][j];
		}
	}

	printf("%d\n", dp[N][K]);
}