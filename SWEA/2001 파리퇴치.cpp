#include<cstdio>
using namespace std;

int map[15][15];

int main() {

	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {

		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		int result = -999;			// �ִ밪 ���� ����
		for (int iStart = 0; iStart < N - M + 1; iStart++) {	// ó������ M X M ���� ���ؼ� �ִ밪 ���
			for (int jStart = 0; jStart < N - M + 1; jStart++) {
				int sum = 0;
				for (int i = iStart; i < iStart + M; i++) {
					for (int j = jStart; j < jStart + M; j++) {
						sum += map[i][j];
					}
				}
				result = sum > result ? sum : result;
			}
		}
		printf("#%d %d\n", test, result);
	}
}