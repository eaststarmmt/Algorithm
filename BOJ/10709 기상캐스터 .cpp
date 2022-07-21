#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int R, C;
char cloud[105][105];
int result[105][105];

int main() {
	scanf("%d %d", &R, &C);
	memset(result, -1, sizeof(result));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %1c", &cloud[i][j]);
			if (cloud[i][j] == 'c') {
				result[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		int idx = C;
		for (int j = 0; j < C; j++) {
			if (cloud[i][j] == 'c') {
				idx = j;
				break;
			}
		}	// end of for j

		int cnt = 0;
		for (int j = idx + 1; j < C; j++) {
			if (cloud[i][j] == 'c') {
				cnt = 0;
				continue;
			}
			result[i][j] = ++cnt;
		}
	}	// end of for i

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}