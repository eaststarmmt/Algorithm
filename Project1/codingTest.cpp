#include<stdio.h>
using namespace std;

int main() {
	int dp[12] = { 0 };
	int t;
	scanf("%d", &t);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int test = 0; test < t; test++) {
		int n;
		scanf("%d", &n);
		
		for (int i = 4; i <= n; i++) {			// d[i - 1] d[i - 2] d[i - 3] �� ��쿡 ���� 1, 2, 3�� �ڿ� �ٿ��ָ� ��. �� ����� ���� ������ ����
			if(dp[i] == 0)
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		printf("%d\n", dp[n]);
	}
}