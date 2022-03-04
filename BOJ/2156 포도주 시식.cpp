#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int wine[10001];
	int dp[10001];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &wine[i]);
	}
	dp[0] = wine[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= n; i++) {	// ���� ���� �������Ƿ� �ּ��� ������ ������ Ȯ�� �Ǿ��־�� ��. �̷� ��� 0��° ���� 0���� ���� ���� Ȯ�� ����
		dp[i] = max(max(dp[i - 2] + wine[i], dp[i - 1]), dp[i - 3] + wine[i - 1] + wine[i]);	
	}

	printf("%d\n", dp[n]);

}