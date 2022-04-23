#include<vector>
#include<queue>
using namespace std;

struct Info {
	int r, c, len;
};

bool visited[100][100];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int bfs(vector<vector<int>>& maps) {
	// 맵 가로 세로 길이 측정
	int R = maps.size();
	int C = maps[0].size();

	queue<Info> Q;
	Q.push({ 0, 0, 1 });
	visited[0][0] = true;

	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		int len = Q.front().len;
		Q.pop();
		if (r == R - 1 && c == C - 1) {
			return len;
		}
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			// 맵 유효성 검사
			if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
			if (maps[nr][nc] == 1) {
				Q.push({ nr, nc, len + 1 });
				visited[nr][nc] = true;
			}

		}
	}   // end of while
	return -1;
}

int solution(vector<vector<int> > maps)
{
	int answer = bfs(maps);
	return answer;
}