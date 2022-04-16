#include<cstdio>
using namespace std;

int map[10][10];

int main() {
	
	int flag = true;
	for (int i = 1; i <= 9; i++) {
		int counting[10] = { 0 };
		for (int j = 1; j <= 9; j++) {
			scanf("%d", &map[i][j]);
			counting[map[i][j]]++;
			if (counting[map[i][j]] > 1) flag = false;
		}
	}
	if (!flag) {
		printf("%d", 0);
		// TODO: 탈출
	}

	for (int i = 1; i <= 9; i++) {
		int counting[10] = { 0 };
		for (int j = 1; j <= 9; j++) {
			counting[map[j][i]]++;
			if (counting[map[j][i]] > 1) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}

	if (!flag) {
		printf("%d", 0);
		// TODO: 탈출
	}

	for (int iStart = 1; iStart <= 7; iStart += 3) {
		for (int jStart = 1; jStart <= 7; jStart += 3) {
			int counting[10] = { 0 };
			for (int i = iStart; i < iStart + 3; i++) {
				for (int j = jStart; j < jStart + 3; j++) {
					counting[map[i][j]]++;
					if (counting[map[i][j]] > 1) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
		}
	}

	if (!flag) {
		printf("%d", 0);
		// TODO: 탈출
	}
	else {
		printf("%d", 1);
	}

}