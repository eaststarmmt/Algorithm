#include<stdio.h>
using namespace std;

int map[129][129];
int blue;
int white;
void divCon(int x, int y, int size) {
	int check = map[x][y];	//�ڶ� ���ϱ� ���� ù��° �� ����
	if (size == 1) {	//ũ�� 1�̸� ī���ø� �ϰ� ����
		if (check == 1) {
			blue++;
			return;
		}
		else {
			white++;
			return;
		}
	}		//x y ��ǥ �򰥸��� �ǰ�����. �̷����� �ι� ���� �����ϰ� Ǯ��
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (check != map[i][j]) {		//�� �ٸ��� ��ͷ� �Ѿ��
				divCon(x, y, size / 2);		
				divCon(x + (size / 2), y, size / 2);
				divCon(x, y + (size / 2), size / 2);
				divCon(x + (size / 2), y + (size / 2), size / 2);
				return;
			}
		}
	}
	if (check == 1) {
		blue++;
		return;
	}
	
	else {
		white++;
		return;
	}
	
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	divCon(1, 1, n);
	printf("%d\n%d\n", white, blue);
}