#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int visited[104][104];
int R, C;

int dfs(int r, int c, vector<string>& map) {
	visited[r][c] = 1;
	int res = map[r][c] - '0';

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
		if (visited[nr][nc]) continue;
		if (map[nr][nc] == 'X') continue;

		res += dfs(nr, nc, map);
	}   // end of for 

	return res;
}

vector<int> solution(vector<string> maps) {
	vector<int> answer;
	R = maps.size();
	C = maps[0].size();

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j] && maps[i][j] != 'X') {
				answer.push_back(dfs(i, j, maps));
			}
		}   // end of for C
	}   // end of for R

	if (answer.empty()) {
		answer.push_back(-1);
	}
	else {
		sort(answer.begin(), answer.end());
	}
	return answer;
}