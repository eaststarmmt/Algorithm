#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 1000

int main() {
	int n;
	scanf("%d", &n);

	int dp[MAX];
	int input[MAX];

	int result = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
	
	for (int i = 0; i < n; i++) {	// 먼저 나가고 있는 애
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (input[i] > input[j]) {
				dp[i] = max(dp[i], dp[j] + 1);	// j번째 항 보다는 크기 때문에 무조건 1 더 큼
			}
		}
		result = max(result, dp[i]);	// i번째 항보다 이전에 더 큰게 있으면 그걸 뽑아야 됨
	}									// 뒤에서 앞을 보는 방식이므로 i 에서 바라본 최대만 들어갈 뿐 전체의 최대가 들어가진 않음
	
	printf("%d\n", result);
}