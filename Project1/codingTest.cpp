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

		for (int i = 0; i < N; i++) {		// ������ Ȯ��
			int cnt = 0;

			for (int j = 0; j < N; j++) {

				if (cnt == K) {				// K�� ��ŭ ���� �ְ� �� ����ĭ�� ���������� + 1
					if (map[i][j] == 0) result++;
				}

				if (map[i][j] == 0) {
					cnt = 0;
				}
				else {
					cnt++;
				}
			}
			if (cnt == K) result++;			// ������ĭ�� ���ͼ� ���� ���ǿ��� +1�� ���Ѱ�� 
		}

		for (int i = 0; i < N; i++) {	// ������ Ȯ��
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