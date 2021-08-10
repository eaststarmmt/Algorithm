#include<stdio.h>
#define MAX 200 + 1

int main() {

	int n, k;
	scanf("%d %d", &n, &k);
	long long dp[MAX][MAX] = { 0 };

	for (int i = 0; i <= n; i++) {
		dp[i][1] = 1;
		dp[i][2] = i + 1;
	}

	for (int i = 3; i <= k; i++) {			
		for (int j = 0; j <= n; j++) {
			for(int z = 0; z <= j; z++) {						// ex> n = 20 k = 3 �̶� �������� �� k = 2 �� 0 ~ 20 ������ ���� + 20 ~ 0 �� ���ϴ� ���
				dp[j][i] += (dp[j - z][i - 1]) % 1000000000;	// �� k = 2 �� 0 ~ 20 ������ ���ڸ� ����� ����� ���� �� ���ϸ� ��
			}
		}
	}
	
	printf("%lld", dp[n][k] % 1000000000);
}