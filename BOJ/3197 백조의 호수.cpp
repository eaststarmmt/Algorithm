#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int R, C;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
char map[1504][1504];
bool visited_swan[1504][1504], visited_water[1504][1504];
queue<pair<int, int>> swan_q, water_q;

bool move() {	// 백조 이동
	queue<pair<int, int>> Q;
	while (!swan_q.empty()) {
		int r = swan_q.front().first;
		int c = swan_q.front().second;
		swan_q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited_swan[nr][nc]) {
				continue;
			}

			if (map[nr][nc] == 'X') {	// 빙판이면 다음 이동에 사용할 큐에 저장
				Q.push({ nr, nc });
			}
			else if (map[nr][nc] == '.') {	// 물이면 이동
				swan_q.push({ nr, nc });
			}
			else {					// 백조 만났으면 종료 조건
				return true;
			}
			visited_swan[nr][nc] = true;
		}	// end of for i
	}	// end of while swan_Q
	swan_q = Q;			// 다음 이동 시작할 빙판 swan_Q로 이동
	return false;
}

void melt() {
	queue<pair<int, int>> Q;
	while (!water_q.empty()) {
		int r = water_q.front().first;
		int c = water_q.front().second;
		water_q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited_water[nr][nc]) {
				continue;
			}

			if (map[nr][nc] == 'X') {	// 기존의 물은 이미 갔음. 새로 물이 되는 지점만 큐에 저장
				Q.push({ nr, nc });
				map[nr][nc] = '.';		// 큐를 따로 쓰고 visited까지 체크해서 바로 바꾸더라도 중복 안일어남
				visited_water[nr][nc] = true;
			}

		}	// end of for i
	}	// end of for while

	water_q = Q;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	int swan_r, swan_c;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {		// 백조가 있는 곳도 물임. 같이 안넣으면 안녹는 경우 생길 수 있음
				swan_r = i;
				swan_c = j;
				visited_water[i][j] = true;
				water_q.push({ i, j });
			}
			else if (map[i][j] == '.') {	
				visited_water[i][j] = true;
				water_q.push({ i, j });
			}
		}	// end of for j
	}	// end of for i

	swan_q.push({ swan_r, swan_c });
	visited_swan[swan_r][swan_c] = true;
	int res = 0;
	while (true) {
		if (move()) {
			break;
		}
		melt();
		res++;
	}	// end of while
	cout << res << "\n";
	return 0;
}