#include <stdio.h>
#include<iostream>
#define MAXR 15
#define MAXC 35
using namespace std;

int N, M, H;	// N: 세로 개수 M: 가로 개수 H 가로선을 놓을수 있는 행 개수
int map[MAXR][MAXC];

bool answer() {
	for (int c = 1; c <= N; c++) {
		int curC = c;
		for (int r = 1; r <= H; r++) {	// 내려가면서 확인
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
	if (end == index) {		// 선 개수 다 그었을 경우
		if (answer()) {
			printf("%d", index);
			exit(0);
		}
		return;
	}
	
	int x = c + 1 > H ? r + 1 : r;	// 마지막 세로줄인 경우 다음줄로 내려감
	int y = c + 1 > H ? 0 : c + 1;	// 마지막 세로줄인 경우 다음줄로 내려가서 처음으로 감

	for (; x <= H; x++) {
		for (; y <= N; y++) {
			if (map[x][y - 1] == 1 || map[x][y] == 1 || map[x][y + 1] == 1)
				continue;
			map[x][y] = 1;
			addLine(end, index + 1, x, y);	// 윗줄에서 줄 하나 더 그어서 1 늘려서 보냄
			map[x][y] = 0;
		}
		y = 1; // 초기화가 밖에서 되었기 때문에 처음으로 돌아가야 됨
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
				if (map[i][j - 1] == 1 || map[i][j] == 1 || map[i][j + 1])	// 이어지는 경우 있으면 안됨
					continue;
				map[i][j] = 1;
				addLine(line, 1, i, j);
				map[i][j] = 0;

			}
		}
	}
	printf("%d", -1);
}

