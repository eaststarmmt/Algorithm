#include<cstdio>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		
		int N;
		scanf("%d", &N);
		int map[8][8] = { 0, };
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		printf("#%d\n", test);
		for (int i = 1; i <= N; i++) {
			for (int j = N; j >= 1; j--) {
				printf("%d", map[j][i]);
			}
			printf(" ");

			for (int j = N; j >= 1; j--) {
				printf("%d", map[N - i + 1][j]);
			}
			printf(" ");

			for (int j = N; j >= 1; j--) {
				printf("%d", map[N - j + 1][N - i + 1]);
			}
			printf("\n");
		}
	}
}

/*
3
1 2 3
4 5 6
7 8 9
6
6 9 4 7 0 5
8 9 9 2 6 5
6 8 5 4 9 8
2 2 7 7 8 4
7 5 1 9 7 9
8 9 3 9 7 6
*/