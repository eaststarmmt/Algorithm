#include<stdio.h>
#include<algorithm>
using namespace std;

int d[1001][3]; //���� ������ �ּڰ� �޾Ƴ��ߵ�. ������ ���� ���� ��� �ٲ�� ����
int color[3];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", &color[j]);
		for (int j = 0; j < 3; j++) { // ���� ���� �� �ּڰ��� ���� ���� ���� ����.
			d[i][j] = min(d[i - 1][(j + 1) % 3], d[i - 1][(j + 2) % 3]) + color[j];
		}
	}
	printf("%d\n", min(d[n][0], min(d[n][1], d[n][2])));
}