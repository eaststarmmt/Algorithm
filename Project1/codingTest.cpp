#include<stdio.h>
using namespace std;

int quad[65][65];
int n;

void divide(int x, int y, int size) {
	if (size == 1) {
		printf("%d", quad[x][y]);
		return;
	}
	for (int i = x; i < x + size; i++) {	
		for (int j = y; j < y + size; j++) {	// j �� �����Ҷ����� ���������� �̵�
			if (quad[i][j] != quad[x][y]) {		// ó�����̶� �ٸ��� �ٷ� ����
				printf("(");				//���� �������� ��ȣ ����
				divide(x, y, size / 2);			//���� ��
				divide(x, y + (size / 2), size / 2);	//������ ��
				divide(x + (size / 2), y, size / 2);	//���� �Ʒ�
				divide(x + (size / 2), y + (size / 2), size / 2);	//������ �Ʒ�
				printf(")");		// �ɰ��� �κ� ���⼭ ����. �׷��Ƿ� ���⼭ ��ȣ ������ ��
				return;				// ���� ���� ���� ��ͷ� ������ �� �Ʒ��� �� �ʿ� ����
			}
		}
	}
	printf("%d", quad[x][y]);	//������ ���� �� �����µ� ������ �� ���
	
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &quad[i][j]);
		}
	}
	
	divide(1, 1, n);
	printf("\n");
}