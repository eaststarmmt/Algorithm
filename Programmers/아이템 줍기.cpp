#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Info {
	int r, c;
};

vector<vector<int>> map;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int bfs(int characterX, int characterY, int itemX, int itemY) {
	queue<Info> Q;
	Q.push({ characterY, characterX });

	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		Q.pop();

		if (c == itemX && r == itemY) {  // 1일때만 큐에 들어가기 때문에 처음 도착했을때가 최솟값
			return map[r][c];
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (map[nr][nc] == 1) {
				map[nr][nc] = map[r][c] + 1;
				Q.push({ nr, nc });
			}
		}

	}   // end of while
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	int answer = 0;
	characterX *= 2;
	characterY *= 2;
	itemX *= 2;
	itemY *= 2;
	map = vector<vector<int>>(110, vector<int>(110));

	for (int i = 0; i < rectangle.size(); i++) {
		for (int j = 0; j < rectangle[i].size(); j++) {
			rectangle[i][j] *= 2;
		}   // end of for j
		int c1 = rectangle[i][0];
		int r1 = rectangle[i][1];
		int c2 = rectangle[i][2];
		int r2 = rectangle[i][3];

		for (int r = r1; r <= r2; r++) {     // 사각형 전체 1로 표시
			for (int c = c1; c <= c2; c++) {
				map[r][c] = 1;
			}   // end of for c
		}   // end of for r      
	}   // end of for i

	for (int i = 0; i < rectangle.size(); i++) {
		int c1 = rectangle[i][0];
		int r1 = rectangle[i][1];
		int c2 = rectangle[i][2];
		int r2 = rectangle[i][3];

		for (int r = r1 + 1; r < r2; r++) {     // 사각형 내부 0으로 표시
			for (int c = c1 + 1; c < c2; c++) {
				map[r][c] = 0;
			}   // end of for c
		}   // end of for r 
	}   // end of for i

	answer = bfs(characterX, characterY, itemX, itemY) / 2; // 모든 좌표를 2배로 늘렸기 때문에 반으로 줄여야 됨

	return answer;
}