#include<cstdio>
#define endl "\n"
using namespace std;

int dp[500][500][2];
int b[3];

int bead(int k1, int k2, int seq) {	// seq 1이면 A차례 0이면 B
	if (dp[k1][k2][seq] >= 0)	// 0 이상이면 그대로 리턴
		return dp[k1][k2][seq];
	if(k1 == 0 && k2 == 0)		// 둘다 0이면 어차피 구슬 비었으므로 현재 차례가 졌으므로 0 리턴
		return dp[k1][k2][seq] = 0;
	for (int i = 0; i < 3; i++) {
		if (b[i] <= k1 && !bead(k1 - b[i], k2, 1 - seq)) {	// 남은 구슬이 현재 뽑는 방법보다 많고, 다음 차례가 졌을경우 이김
			return dp[k1][k2][seq] = 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (b[i] <= k2 && !bead(k1, k2 - b[i], 1 - seq)) {		
			return dp[k1][k2][seq] = 1;
		}
	}
	return 0;	// 여기까지 오면 하나라도 이길 수 있는 경우의 수를 다 피했으므로 졌음
}

int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < 500; i++) {			// 계산 안한 값들 다 -1로 초기화
		for (int j = 0; j < 500; j++) {
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}
	for (int i = 0; i < 5; i++) {
		int k1, k2;
		scanf("%d %d", &k1, &k2);
		if (bead(k1, k2, 1))	// 1이 나오면 A가 이김
			printf("A\n");
		else
			printf("B\n");
	}
}