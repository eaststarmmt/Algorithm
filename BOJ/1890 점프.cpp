#include<stdio.h>
#define MAX 100

int main() {

	int N;
	scanf("%d", &N);
	int map[MAX][MAX];
	long long dp[MAX][MAX] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1) continue;		// �̰� ������ �������� ������������ ���� ��ġ�� �ι� ���ع���
			if (i + map[i][j] < N)						// �����ؼ� ������ ƨ���� �ʴ� ��츸 
				dp[i + map[i][j]][j] += dp[i][j];		// dp�� ���� �������� �� ����� ���� ��� ����.
			if (j + map[i][j] < N)						// �鸮�� �ʴ� ���� ��� 0���� ����
				dp[i][j + map[i][j]] += dp[i][j];

		}
	}
	printf("%lld\n", dp[N - 1][N - 1]);
}