#include<stdio.h>
#include<cmath>
using namespace std;

char star[1024][1024];

void recursive(int x, int y, int size) {
	if (size == 1) {
		star[x][y] = '*';
		return;
	}
	size /= 2;				// size�� 2�� ������ 1�� �ɶ��� ���. 
	recursive(x, y, size);	// ����� 1�� �����⾿ ������ �����ϴ� ��Ģ��
	recursive(x + size, y, size);
	recursive(x, y + size, size);
}

int main() {
	int n;
	scanf("%d", &n);
	int size = pow(2, n);		// size�� 2^n ���� ����
	recursive(0, 0, size);	
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == size - i)	// ���� ���� ��� size���� �ϳ��� �پ��. ���� ���� ����ϱ� ����
				break;
			if (star[i][j] == '*')	// �迭���� *�� ������ ��� �ƴϸ� ����
				printf("%c", star[i][j]);
			else 
				printf(" ");
		}
		if(i != size - 1)		// �������� �ٹٲ��� ���ֱ� ����
			printf("\n");
	}
	
}