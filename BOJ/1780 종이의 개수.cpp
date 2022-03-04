#include<stdio.h>
using namespace std;

int paper[2188][2188];
int result[3];

void divide(int x, int y, int size) {
	if (size == 1) {		//크기가 1이면 바로 카운팅
		result[paper[x][y] + 1]++;
		return;
	}
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (paper[x][y] != paper[i][j]) {		//다른게 나오면 재귀로 9등분 해서 다시 확인. 리턴 안하면 중복 카운팅됨
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						divide(x + a * size / 3, y + b * size / 3, size / 3);
					}
				}
				return;
			}
		}
	}
	result[paper[x][y] + 1]++;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	divide(1, 1, n);
	for (int i = 0; i < 3; i++)
		printf("%d\n", result[i]);
}