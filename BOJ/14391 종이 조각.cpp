#include <cstdio>
#include <algorithm>
using namespace std;

int R, C;
int map[5][5];
int main() {
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%1d", &map[i][j]);
		}	// end of for j
	}	// end of for i
	int res = 0;
	for (int s = 0; s < 1 << (R * C); s++) {
		int sum = 0;
		for (int i = 0; i < R; i++) {	// 세로 기준으로 계산
			int cur = 0;
			for (int j = 0; j < C; j++) {
				int k = i * C + j;	// 행열 1차원으로 인덱싱
				if (s & (1 << k)) {
					sum += cur;
					cur = 0;
				}
				else {
					cur = cur * 10 + map[i][j];
				}
			}	// end of for j
			if (cur) {	// 열이 끝났는데 sum에 저장 안한거 있으면 저장
				sum += cur;
				cur = 0;
			}
		}	// end of for i

		for (int j = 0; j < C; j++) {
			int cur = 0;
			for (int i = 0; i < R; i++) {
				int k = i * C + j;	// 행열 1차원으로 인덱싱
				if (s & (1 << k)) {
					cur = cur * 10 + map[i][j];
				}
				else {
					sum += cur;
					cur = 0;
				}	// end of for i
			}
			if (cur) {	// 행이 끝났는데 sum에 저장 안한거 있으면 저장
				sum += cur;
				cur = 0;
			}
		}	// end of for j

		res = max(res, sum);
	}	// end of for s
	printf("%d\n", res);
	return 0;
}