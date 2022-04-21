#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[500][500][4];  // 방향까지도 고려 해야 됨
int R, C;
int dr[] = { -1, 0, 1, 0 };   // 상 우 하 좌. +시 우회전 -시 좌회전
int dc[] = { 0, 1, 0, -1 };

int cycle(vector<string>& grid, int r, int c, int d) {
	int ans = 0;
	// 사이클이 어디서 시작하던 상관없이 길이만 구하면 됨
	while (!visited[r][c][d]) {  // 방문 했던곳이면 탈출
		visited[r][c][d] = true;
		ans++;
		// 어디서 왔던 네방향 다 볼거라서 현재 격자에 맞게 다 돌리면 결국 다 확인 가능
		// grid에 맞게 회전
		if (grid[r][c] == 'R')
			d = d == 3 ? 0 : d + 1;
		else if (grid[r][c] == 'L')
			d = d == 0 ? 3 : d - 1;
		// 해당 방향으로 전진
		// 음수 일 경우를 대비해서 행이나 열 크기 만큼 더하고 나머지를 계산
		r = (r + dr[d] + R) % R;
		c = (c + dc[d] + C) % C;
	}   // end of while

	return ans;
}

vector<int> solution(vector<string> grid) {
	vector<int> answer;
	R = grid.size();    // map 의 행과 열의 크기 미리 구함
	C = grid[0].size();
	// 모든 곳에서 4방 다 확인해서 사이클 있는거 확인해야 됨.
	// visited로 이미 갔으면 이미 그건 다른 사이클에서 찾아졌다는 의미임
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int d = 0; d < 4; d++) {
				if (!visited[i][j][d]) {
					answer.push_back(cycle(grid, i, j, d));
				}
			}   // end of for d
		}   // end of for j
	}   // end of for i
	sort(answer.begin(), answer.end());
	return answer;
}