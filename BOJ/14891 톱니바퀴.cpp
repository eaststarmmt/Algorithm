#include<cstdio>
using namespace std;

int sawtooth[5][8];

void turn(int tooth, int dir) {
	int temp = sawtooth[tooth][0];
	if (dir == 1) {		// 시계방향
		sawtooth[tooth][0] = sawtooth[tooth][7];
		for (int i = 6; i >= 1; i--) {
			sawtooth[tooth][i + 1] = sawtooth[tooth][i];
		}
		sawtooth[tooth][1] = temp;
	}

	else {
		for (int i = 1; i < 8; i++) {
			sawtooth[tooth][i - 1] = sawtooth[tooth][i];
		}
		sawtooth[tooth][7] = temp;
	}
}

void leftCheck(int tooth, int dir) {	// 재귀로 왼쪽을 먼저 다 확인 해야 값이 바뀌어서 안돌아가는 경우를 방지할 수 있음
	if (tooth < 1) return;
	if (tooth - 1 > 0 && sawtooth[tooth - 1][2] != sawtooth[tooth][6])
		leftCheck(tooth - 1, -1 * dir);
	turn(tooth, dir);
}

void rightCheck(int tooth, int dir) {// 재귀로 오른쪽을 먼저 다 확인 해야 값이 바뀌어서 안돌아가는 경우를 방지할 수 있음
	if (tooth > 4) return;
	if (tooth + 1 < 5 && sawtooth[tooth][2] != sawtooth[tooth + 1][6])
		rightCheck(tooth + 1, -1 * dir);
	turn(tooth, dir);
}

int main() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &sawtooth[i][j]);
		}
	}

	int K;
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int tooth, dir;
		scanf("%d %d", &tooth, &dir);

		// 왼쪽 먼저 돌리기
		if (tooth - 1 > 0 && sawtooth[tooth - 1][2] != sawtooth[tooth][6])
			leftCheck(tooth - 1, -1 * dir);

		// 오른쪽 먼저 돌리기
		if (tooth + 1 < 5 && sawtooth[tooth][2] != sawtooth[tooth + 1][6])
			rightCheck(tooth + 1, -1 * dir);

		turn(tooth, dir);

	}
	int result = 0;
	for (int i = 1; i <= 4; i++) {
		if (sawtooth[i][0] == 1)
			result += 1 << (i - 1);
	}
	printf("%d\n", result);
}