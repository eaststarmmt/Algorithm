#include<cstdio>
using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	int map[100][100] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	bool flag = true;

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			sum += map[i][j];
		}
		if (sum % 2 != 0) {
			flag = false;
			break;
		}

		sum = 0;
		for (int j = 0; j < N; j++) {
			sum += map[j][i];
		}
		if (sum % 2 != 0) {
			flag = false;
			break;
		}
	}
	if (flag) {
		printf("OK\n");
		return 0;
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			map[r][c] = (map[r][c] + 1) % 2;
			flag = true;
			for (int i = 0; i < N; i++) {
				int sum = 0;
				for (int j = 0; j < N; j++) {
					sum += map[i][j];
				}
				if (sum % 2 != 0) {
					flag = false;
					break;
				}

				sum = 0;
				for (int j = 0; j < N; j++) {
					sum += map[j][i];
				}
				if (sum % 2 != 0) {
					flag = false;
					break;
				}
			}
			if(!flag) map[r][c] = (map[r][c] + 1) % 2;
			else {
				printf("Change bit (%d,%d)\n", r + 1, c + 1);
				return 0;
			}
		}
	}
	printf("Corrupt\n");
}