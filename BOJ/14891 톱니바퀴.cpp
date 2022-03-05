#include<cstdio>
using namespace std;

int sawtooth[5][8];

void turn(int tooth, int dir) {
	int temp = sawtooth[tooth][0];
	if (dir == 1) {		// �ð����
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

void leftCheck(int tooth, int dir) {	// ��ͷ� ������ ���� �� Ȯ�� �ؾ� ���� �ٲ� �ȵ��ư��� ��츦 ������ �� ����
	if (tooth < 1) return;
	if (tooth - 1 > 0 && sawtooth[tooth - 1][2] != sawtooth[tooth][6])
		leftCheck(tooth - 1, -1 * dir);
	turn(tooth, dir);
}

void rightCheck(int tooth, int dir) {// ��ͷ� �������� ���� �� Ȯ�� �ؾ� ���� �ٲ� �ȵ��ư��� ��츦 ������ �� ����
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

		// ���� ���� ������
		if (tooth - 1 > 0 && sawtooth[tooth - 1][2] != sawtooth[tooth][6])
			leftCheck(tooth - 1, -1 * dir);

		// ������ ���� ������
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