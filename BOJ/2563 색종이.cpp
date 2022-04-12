#include<stdio.h>

int main() {
	int paper[100][100] = { 0 };
	int num;
	int cnt = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (paper[j + y][k + x] != 1) {		// 칸 입력 받으면서 카운팅
					paper[j + y][k + x] = 1;
					cnt++;
				}
			}
		}
	}
	printf("%d", cnt);
}