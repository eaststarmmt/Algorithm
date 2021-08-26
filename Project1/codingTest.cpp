#include<cstdio>
using namespace std;

int map[15][15];

int main() {

	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		int N, K;
		scanf("%d %d", &N, &K);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		int result = 0;

		for (int i = 0; i < N; i++) {		// 가로줄 확인
			int cnt = 0;

			for (int j = 0; j < N; j++) {

				if (cnt == K) {				// K개 만큼 공간 있고 그 다음칸이 막혀있으면 + 1
					if (map[i][j] == 0) result++;
				}

				if (map[i][j] == 0) {
					cnt = 0;
				}
				else {
					cnt++;
				}
			}
			if (cnt == K) result++;			// 마지막칸에 들어와서 위의 조건에서 +1을 못한경우 
		}

		for (int i = 0; i < N; i++) {	// 세로줄 확인
			int cnt = 0;

			for (int j = 0; j < N; j++) {

				if (cnt == K) {
					if (map[j][i] == 0) result++;
				}

				if (map[j][i] == 0) {
					cnt = 0;
				}
				else {
					cnt++;
				}
			}
			if (cnt == K) result++;
		}

		printf("#%d %d\n", test, result);
	}
}

/*
5 3
0 0 1 1 1
1 1 1 1 0
0 0 1 0 0
0 1 1 1 1
1 1 1 0 1
5 3
1 0 0 1 0
1 1 0 1 1
1 0 1 1 1
0 1 1 0 1
0 1 1 1 0
*/