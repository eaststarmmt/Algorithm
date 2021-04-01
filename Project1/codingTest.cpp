#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int dp[502][502];	//dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);�� ��ȭ�Ŀ��� ���ʰ� �������� ������ ���� �����ϱ� ���� 502�� ��. 
int main() {		// ���۵� 1���� �ؾ� ��
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
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);	//�ﰢ�� �ε��� ���� ���� ���ؾߵ�.
		}														//���� ���� ����ϰ� ������ ���� ��. �׸����� �ؿ��� ���� �Ǵ°� ����!!
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (result < dp[n][i]) 
			result = dp[n][i];
	}
	printf("%d\n", result);
}