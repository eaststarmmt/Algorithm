#include<stdio.h>
#include<algorithm>
using namespace std;

int sticker[2][100001];
int dp[2][100001];

int main() {
	int T;
	scanf("%d", &T);

	for (int test = 1; test <= T; test++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &sticker[i][j]);
				dp[i][j] = 0;
			}
		}
		
		dp[0][0] = sticker[0][0];	// dp[0][0]�� 00�� ��ƼĿ�� ������ ���� ���
		dp[1][0] = sticker[1][0];
		dp[0][1] = dp[1][0] + sticker[0][1];
		dp[1][1] = dp[0][0] + sticker[1][1];

		for (int i = 2; i < n; i++) {
			dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);		// �밢�� �ʿ� ��ƼĿ�� ���� ���� �� �ٷ� �� ��ƼĿ�� ���°�� �� ū  ��츦 ���� ��ƼĿ ������ ���� ������
			dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		printf("%d\n", max(dp[0][n - 1], dp[1][n - 1]));		// �� �Ʒ��߿� �� ū �� ���
	}
}