#include<stdio.h>

int sum[1025][1025];
int map[1025][1025];

int main() {

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j ++) {
			scanf("%d", &map[i][j]);
		}
	}	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			
			sum[i][j] = map[i][j] - sum[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j];		// i,j ������ ���� ���ص�. �ߺ����� �������� �κ��� ����
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]);	// �ߺ����� �� �κ� �ٽ� ������
	}

}