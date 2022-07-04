#include <cstdio>
#include <algorithm>
#define INF 1e18
using namespace std;

long long dp[101] = { 0, 0, 1, 7, 4, 2, 6, 8, 10, };	// 8에 10이 들어오면서 처음으로 0이 나오기때문에 8까지는 넣어줘야됨
long long num[] = { 0, 0, 1, 7, 4, 2, 0, 8 };		// 6에 0 때문에 따로 만듬
void min_num() {
	for (int i = 9; i <= 100; i++) {
		dp[i] = INF;
		for (int j = 2; j <= 7; j++) {
			dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);	// 이전에 나온 값과 한자리 수 범위인 2~7 범위를 더한것 중 최소인 값을 선택하는 방식
		}	// end of for
	}
}

int main() {
	int Test;
	scanf("%d", &Test);

	min_num();

	for (int test = 1; test <= Test; test++) {
		int n;
		scanf("%d", &n);
		printf("%lld ", dp[n]);
		if (n % 2 != 0) {
			printf("7");
			n -= 3;
		}
		while (n > 0) {
			printf("1");
			n -= 2;
		}
		printf("\n");
	}	// end of for
}