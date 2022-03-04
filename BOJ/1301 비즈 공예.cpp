#include<cstdio>
#include<cstring>
using namespace std;

int N, sum;
long long dp[6][6][11][11][11][11][11];
int bead[6];

long long calc(int ppre, int pre, int a, int b, int c, int d, int e) {
	if (a + b + c + d + e == 0) return 1;	// ������ ������ + 1
	if (dp[ppre][pre][a][b][c][d][e] != -1) return dp[ppre][pre][a][b][c][d][e];	// ������� �� �� ������ �� �׳� ����. ������ �ٴڿ��� ��� ���ϰ� ����
	dp[ppre][pre][a][b][c][d][e] = 0;
	// ���� �ϳ��� ����ϸ鼭 ���� ���� ���¿��� ����� �� �ִ� ����� �� ��� ���ϱ�
	if (ppre != 1 && pre != 1 && a > 0) dp[ppre][pre][a][b][c][d][e] += calc(pre, 1, a - 1, b, c, d, e);
	if (ppre != 2 && pre != 2 && b > 0) dp[ppre][pre][a][b][c][d][e] += calc(pre, 2, a, b - 1, c, d, e);
	if (ppre != 3 && pre != 3 && c > 0) dp[ppre][pre][a][b][c][d][e] += calc(pre, 3, a, b, c - 1, d, e);
	if (ppre != 4 && pre != 4 && d > 0) dp[ppre][pre][a][b][c][d][e] += calc(pre, 4, a, b, c, d - 1, e);
	if (ppre != 5 && pre != 5 && e > 0) dp[ppre][pre][a][b][c][d][e] += calc(pre, 5, a, b, c, d, e - 1);

	return dp[ppre][pre][a][b][c][d][e];	// �� ���� �� ����
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &bead[i]);
		sum += bead[i];
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", calc(0, 0, bead[1], bead[2], bead[3], bead[4], bead[5]));
}