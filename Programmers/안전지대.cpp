#include <string>
#include <vector>

using namespace std;

int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int N;
int a[104][104];

int solution(vector<vector<int>> board) {
	int answer = 0;
	N = board.size();
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (!board[i][j]) continue;
			a[i][j] = 1;
			for (int k = 0; k < 8; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];

				if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
				a[nr][nc] = 1;
			}
		}
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (!a[i][j]) answer++;
		}
	}
	return answer;
}