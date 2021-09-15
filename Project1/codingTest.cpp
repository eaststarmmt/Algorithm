#include<cstdio>
#include<algorithm>
#define MAX 100001
using namespace std;

int weight[101];
int value[MAX];
int dp[101][MAX];	// [������ ��ȣ][������� �ϴ� ����]

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}

	for (int i = 1; i <= N; i++) {	// ������ ��ȣ
		for (int j = 1; j <= K; j++) {	// ������� �ϴ� ����
			if (j >= weight[i])	// ������� �ϴ� ���԰� ���� Ȯ���ϴ� ������ ���Ժ��� Ŀ�� ���� �� ����
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);	// ���� ���Ǳ��� ��Ƽ� ��ǥ ���Ը� ���� ���� 
							// �������Ǳ��� ��Ƽ� ������� �ϴ� ���� - ���� ������ ������ ��ġ�� ���� ������ ��ġ�� ���Ѱ��� ū �� ����

			else		// ��ǥ ���Ժ��� ���� ������ ���԰� Ŀ�� ������ ���� ���ϹǷ� ���� ���Ǳ��� Ȯ���ߴ� ��ġ�� �״�� ����
				dp[i][j] = dp[i - 1][j];
		}
	}

	printf("%d\n", dp[N][K]);
}