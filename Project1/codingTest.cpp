#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[301];	// ����� ������ ��� ����� �迭�� dp�� ����� �迭�� ���� ���� �ؾߵ�
int sta[301];	// �ȱ׷��� ����� �ι��� �Ǳ� ������ ���� ���� Ŀ��
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sta[i]);
	}
	dp[1] = sta[1];
	dp[2] = sta[1] + sta[2];
	dp[3] = max(sta[1] + sta[3], sta[2] + sta[3]);	// �ִ��� ���� ã������ ��å�� ����� ��
	for (int i = 4; i <= n; i++) {		// 6���� ���� i - 3 ������ �ִ밪 + i - 1vs i - 2�� �ִ밪�� ū �� ���� �Ŷ��� �� �� ����.
		dp[i] = max(dp[i - 2], dp[i -3] + sta[i - 1]) + sta[i];
	}
	printf("%d\n", dp[n]);
}