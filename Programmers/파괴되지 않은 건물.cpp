#include <string>
#include <vector>

using namespace std;
int accSum[1004][1004];
int R, C;
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	R = board.size();
	C = board[0].size();
	for (vector<int> ski : skill) {
		int type = ski[0] == 1 ? -1 : 1;   // 1이면 공격 2면 회복
		int r1 = ski[1];
		int c1 = ski[2];
		int r2 = ski[3];
		int c2 = ski[4];
		int degree = ski[5];
		// 누적합. 2차원에서 시점 기준 대각선은 양수. 반대쪽 대각은 음수로 둠
		// 기준은 원하는 범위보다 행, 열 둘 다 + 1 크기로 잡아야 됨
		accSum[r1][c1] += degree * type;
		accSum[r1][c2 + 1] += degree * type * -1;
		accSum[r2 + 1][c1] += degree * type * -1;
		accSum[r2 + 1][c2 + 1] += degree * type;
	}

	for (int i = 0; i <= R; i++) {    // 행에 대한 누적합 행렬
		for (int j = 0; j < C; j++) {
			accSum[i][j + 1] += accSum[i][j];
		}
	}

	for (int j = 0; j <= C; j++) {    // 열에 대한 누적합 행렬
		for (int i = 0; i < R; i++) {
			accSum[i + 1][j] += accSum[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] + accSum[i][j] > 0) {
				answer++;
			}
		}
	}

	return answer;
}