#include<cstdio>
#include<algorithm>
#define endl "\n"
using namespace std;

int dp[16];
int t[16];
int p[16];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}	// end of input

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		int nextTime = i + t[i];	// ���� �� ������ ��� ������ �ð�
		int noWork = i + 1;		// �� �������� ��� ����ϱ� ����

		if (nextTime <= N + 1) // N + 1�̸� N �ϱ��� �� �ߴٴ� ����
			dp[nextTime] = dp[i] + p[i] > dp[nextTime] ? dp[i] + p[i] : dp[nextTime];
		else	// �ε��� ���� �Ѿ�°� ����
			nextTime = 0;

		if (noWork <= N + 1)
			dp[noWork] = dp[i] > dp[noWork] ? dp[i] : dp[noWork];
		else
			noWork = 0;
		
		ans = max(ans, max(dp[noWork], dp[nextTime]));	// ���ݱ��� ���� �� �߿� �ִ밪 ���
	}
	printf("%d\n", ans);
}