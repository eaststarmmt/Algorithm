#include <stdio.h>
#include<iostream>
#define MAXR 15
#define MAXC 35
using namespace std;

int N, M, H;	// N: ���� ���� M: ���� ���� H ���μ��� ������ �ִ� �� ����
int map[MAXR][MAXC];

bool answer() {
	for (int c = 1; c <= N; c++) {
		int curC = c;
		for (int r = 1; r <= H; r++) {	// �������鼭 Ȯ��
			int left = map[r][curC - 1];
			if (left == 1) {
				curC--;
				continue;
			}
			int right = map[r][curC];
			if (right == 1) {
				curC++;
				continue;
			}
		}
		if (curC != c) return false;
	}
	return true;
}

void addLine(int end, int index, int r, int c) {
	if (end == index) {		// �� ���� �� �׾��� ���
		if (answer()) {
			printf("%d", index);
			exit(0);
		}
		return;
	}
	
	int x = c + 1 > H ? r + 1 : r;	// ������ �������� ��� �����ٷ� ������
	int y = c + 1 > H ? 0 : c + 1;	// ������ �������� ��� �����ٷ� �������� ó������ ��

	for (; x <= H; x++) {
		for (; y <= N; y++) {
			if (map[x][y - 1] == 1 || map[x][y] == 1 || map[x][y + 1] == 1)
				continue;
			map[x][y] = 1;
			addLine(end, index + 1, x, y);	// ���ٿ��� �� �ϳ� �� �׾ 1 �÷��� ����
			map[x][y] = 0;
		}
		y = 1; // �ʱ�ȭ�� �ۿ��� �Ǿ��� ������ ó������ ���ư��� ��
	}

}

int main() {
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}

	if (answer()) {
		printf("%d", 0);
		return 0;
	}

	for (int line = 1; line <= 3; line++) {
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j - 1] == 1 || map[i][j] == 1 || map[i][j + 1])	// �̾����� ��� ������ �ȵ�
					continue;
				map[i][j] = 1;
				addLine(line, 1, i, j);
				map[i][j] = 0;

			}
		}
	}
	printf("%d", -1);
}

