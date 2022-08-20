#include <string>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

struct Info {
	int r, c, cost, dir;
};

int cost_table[30][30][2];  // 방향 정보가 없으면 그 다음값에서 최소가 달라지기 때문에 추가함 (25번 테케)
int N;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int bfs(vector<vector<int>>& board) {
	N = board.size();
	for (int i = 0; i < N; i++) {    // 최소비용 테이블 10억으로 초기화
		for (int j = 0; j < N; j++) {
			cost_table[i][j][0] = INF;
			cost_table[i][j][1] = INF;
		}
	}

	queue<Info> Q;
	Q.push({ 0, 0, 0, 0 });
	Q.push({ 0, 0, 0, 3 });

	int res = 1e9;
	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		int cost = Q.front().cost;
		int dir = Q.front().dir;

		Q.pop();

		if (r == N - 1 && c == N - 1) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == 1) continue;
			int ncost = cost;
			if (i / 2 == dir / 2) {  // 상하, 좌우로 구분 하므로 01 23의 경우로 나눠서 2로 나눈 몫으로 구분
				ncost += 100;
			}
			else {
				ncost += 600; // 코너를 만들어도 다음으로 넘어가려면 결국 직선도로도 추가 해야 됨
			}
			if (ncost <= cost_table[nr][nc][i / 2]) {	// 같을때도 방향 때문에 최소값을 만들 수 있음
				cost_table[nr][nc][i / 2] = ncost;
				Q.push({ nr, nc, ncost, i });
			}
		}

	}   // end of while

	return min(cost_table[N - 1][N - 1][0], cost_table[N - 1][N - 1][1]);
}

int solution(vector<vector<int>> board) {
	int answer = bfs(board);
	return answer;
}