#include<stdio.h>
using namespace std;

bool dif[50][50];
int a[50][50];
int b[50][50];

void reverse(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			a[i][j] = 1 - a[i][j];
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &b[i][j]);
		}
	}
	int cnt = 0;

	for (int i = 0; i < n - 2; i++) {	
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {	// ���� �ٸ��� a ������
				cnt++;
				reverse(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {	// �ٽ� ó������ ��
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {	// �ϳ��� �ٸ��� �ٷ� �ߴ��ϰ� -1 ���
				printf("%d\n", -1);
				return 0;
			}
		}
	}
	printf("%d", cnt);
}