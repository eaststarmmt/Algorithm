#include<cstdio>
#define MOD 1000000003
using namespace std;

int dp[1001][1001];	// dp[N][K] �� ����

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;		// 0�� ���� ����� ���� ������ 1
		dp[i][1] = i;		// 1�� ���� ����� ���� N
	}

	for (int i = 4; i <= N; i++) {		// N�� 3���ϴ� ����Ŭ�� �߻��� 2���̻� �� �� ����
		for (int j = 2; j <= K; j++) {	// K�� 0�� 1�� ���� ������ �̹� ���� ����
			dp[i][j] = (dp[i - 2][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;	// N -2�� �� K - 1 �� �� ���� N - 1 �� �� K�� ��ŭ �� ����� ���� ����
		}
	}
	printf("%d\n", dp[N][K]);
}