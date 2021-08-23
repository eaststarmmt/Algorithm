#include<stdio.h>
#include<algorithm>
using namespace std;

int maxDp[2][3];
int minDp[2][3];
int map[100001][3];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	maxDp[0][0] = map[1][0];
	minDp[0][0] = map[1][0];
	maxDp[0][1] = map[1][1];
	minDp[0][1] = map[1][1];
	maxDp[0][2] = map[1][2];
	minDp[0][2] = map[1][2];
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {							// j�� 0�϶��� 0�� 1������ �� �� ����
				maxDp[1][j] = map[i][j] + max(maxDp[0][0], maxDp[0][1]);
				minDp[1][j] = map[i][j] + min(minDp[0][0], minDp[0][1]);
			}
			else if (j == 2) {						// j�� 2�϶��� 1�� 2������ �� �� ����
				maxDp[1][j] = map[i][j] + max(maxDp[0][1], maxDp[0][2]);
				minDp[1][j] = map[i][j] + min(minDp[0][1], minDp[0][2]);
			}
			else {
				maxDp[1][j] = map[i][j] + max(max(maxDp[0][0], maxDp[0][1]), maxDp[0][2]);
				minDp[1][j] = map[i][j] + min(min(minDp[0][0], minDp[0][1]), minDp[0][2]);
			}
		}
		for (int j = 0; j < 3; j++) {			// 0���� ������ �÷��ְ� ���� ����� �غ�
			maxDp[0][j] = maxDp[1][j];
			minDp[0][j] = minDp[1][j];
		}
	}
	printf("%d %d\n", max(max(maxDp[0][0], maxDp[0][1]), maxDp[0][2]), min(min(minDp[0][0], minDp[0][1]), minDp[0][2]));
}