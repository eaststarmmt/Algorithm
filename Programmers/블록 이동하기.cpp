#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
	int r1, c1, r2, c2;
};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
bool visited[104][104][104][104];
int N;

vector<Pos> getNextPos(Pos pos, vector<vector<int>>& map) {
	vector<Pos> next_pos;
	// 상하좌우 이동 가능한 범위 담기
	for (int i = 0; i < 4; i++) {
		int nr1 = pos.r1 + dr[i];
		int nr2 = pos.r2 + dr[i];
		int nc1 = pos.c1 + dc[i];
		int nc2 = pos.c2 + dc[i];

		if (visited[nr1][nc1][nr2][nc2]) {   // 이미 방문 한 경우
			continue;
		}
		if (map[nr1][nc1] == 1 || map[nr2][nc2] == 1) {  // 이동 할 수 없는 경우
			continue;
		}

		next_pos.push_back({ nr1, nc1, nr2, nc2 });
	}   // end of for

	//가로로 놓인 경우
	if (pos.r1 == pos.r2) {
		for (int dr : {-1, 1}) { // 아래방향, 위방향 회전 가능 여부
			int nr = pos.r1 + dr;
			if (map[nr][pos.c1] == 1 || map[nr][pos.c2] == 1) {
				continue;
			}
			next_pos.push_back({ pos.r1, pos.c1, nr, pos.c1 });
			next_pos.push_back({ pos.r2, pos.c2, nr, pos.c2 });
		}   // end of for nr
	}
	else {
		for (int dc : {-1, 1}) { // 왼쪽방향, 오른쪽방향 회전 가능 여부
			int nc = pos.c1 + dc;
			if (map[pos.r1][nc] == 1 || map[pos.r2][nc] == 1) {
				continue;
			}
			next_pos.push_back({ pos.r1, pos.c1, pos.r1, nc });
			next_pos.push_back({ pos.r2, pos.c2, pos.r2, nc });
		}   // end of for nr
	}
	return next_pos;
}

int bfs(vector<vector<int>> map) {
	queue<pair<Pos, int>> Q;
	Q.push({ {1, 1, 1, 2}, 0 });
	visited[1][1][1][2] = true;
	visited[1][2][1][1] = true;

	while (!Q.empty()) {
		Pos pos = Q.front().first;
		int time = Q.front().second;
		Q.pop();

		if ((pos.r1 == N && pos.c1 == N) || (pos.r2 == N && pos.c2 == N)) {
			return time;
		}

		vector<Pos> next_pos = getNextPos(pos, map);

		for (Pos npos : next_pos) {
			if (visited[npos.r1][npos.c1][npos.r2][npos.c2])
				continue;
			Q.push({ npos, time + 1 });
			visited[npos.r1][npos.c1][npos.r2][npos.c2] = true;
			visited[npos.r2][npos.c2][npos.r1][npos.c1] = true;
		}   // end of for

	}   // end of while Q

	return 0;
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	N = board.size();
	vector<vector<int>> map(N + 2, vector<int>(N + 2, 1));  // 외각에 벽을 두르기 위해 가로 세로 각각 2씩 더 크게 만들고 1로 초기화. 이러면 범위 벗어나는지 체크 할 필요도 없고, 문제처럼 시작점을 1, 1로 맞출 수 있음
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			map[i + 1][j + 1] = board[i][j];
		}
	}   // end of for board copy

	answer = bfs(map);

	return answer;
}