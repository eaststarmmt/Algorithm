#include<cstdio>
#include<algorithm>
using namespace std;

int map[1001][1001];	
int dp[1001][1001];
int main() {
	int R, C;
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &map[i][j]);
		}
	}	// end of input

	for (int i = 1; i <= R; i++) {		// 0���� �ʱ�ȭ �Ǿ��ֱ� ������ �ʱ�ȭ �ʿ� ����
		for (int j = 1; j <= C; j++) {	// ����, ���� �밢�� ��, ���� �̷��� �������� �ִ밪 + �ڱ� �ڽ����� ����
			dp[i][j] = map[i][j] + max(dp[i][j - 1], max(dp[i - 1][j - 1], dp[i - 1][j]));
		}
	}

	printf("%d\n", dp[R][C]);
}