#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int up_dr[] = { 0, -1, 0, 1 };	// 위쪽 미세먼지 회전 방향
int up_dc[] = { 1, 0, -1, 0 };
int under_dr[] = { 0, 1, 0, -1 };	// 아래쪽 미세먼지 회전 방향
int under_dc[] = { 1, 0, -1, 0 };
vector<pair<int, int>> up_dust, under_dust;	// 미세먼지 위치만 저장
int m[54][54], temp_dust[54][54];
int R, C, T;

void dust_spread() {
	fill(&temp_dust[0][0], &temp_dust[0][0] + 54 * 54, 0);
	queue<pair<int, int>> Q;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (m[i][j] > 0) {		// 미세 먼지 있는 구간 저장
				Q.push({ i, j });
			}
		}	// end of for C
	}	// end of for R

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;

		Q.pop();

		int spread = m[r][c] / 5;

		for (int i = 0; i < 4; i++) {
			int nr = r + up_dr[i];
			int nc = c + up_dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C || m[nr][nc] == -1) {	// 확산 안된 부분은 뺄 필요 없으므로 다음 방향으로
				continue;
			}
			// dust 배열 따로 안만들면 원본 값이 수정되어 값이 틀어짐
			temp_dust[nr][nc] += spread;
			m[r][c] -= spread;		// 현 위치에서 확산 된 만큼 빼줌
		}	// end of for i
	}	// end of while Q

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			m[i][j] += temp_dust[i][j];
		}	// end of for C
	}	// end of for R
}

vector<pair<int, int>> setDust(int startR, int startC, int dr[], int dc[]) {
	vector<pair<int, int>> vec;
	int r = startR;
	int c = startC;
	int d = 0;
	while (true) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C) {	// 끝에 닿았으면 회전
			d++;
			nr = r + dr[d];
			nc = c + dc[d];
		}	// end of if
		if (nr == startR && nc == startC) break;		// 한바퀴 다 돌았으면 break;
		vec.push_back({ nr, nc });
		r = nr;
		c = nc;
	}
	return vec;
}

void turn_dust(vector<pair<int, int>>& dust) {
	// 이미 방향은 잡힌채로 위치만 저장되어 있음. 그냥 한칸씩 밀기만 하면 됨
	for (int i = dust.size() - 1; i > 0; i--) {	// 마지막 인덱스는 공기청정기로 들어가서 사라질것이므로 덮어버리면 됨
		m[dust[i].first][dust[i].second] = m[dust[i - 1].first][dust[i - 1].second];
	}	// end of for dust
	m[dust[0].first][dust[0].second] = 0;	// 공기 청정기 걸치고 나온 부분
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;

	bool flag = false;	// 공기청정기 위 아래 위치 구분하기 위한 flag
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> m[i][j];
			if (m[i][j] == -1) {	// 공기청정기 위치에서 미세먼지 방향만 미리 벡터에 저장
				if (!flag) {
					up_dust = setDust(i, j, up_dr, up_dc);
					flag = true;	// 무조건 위가 먼저 나옴
				}
				else {
					under_dust = setDust(i, j, under_dr, under_dc);
				}
			}
		}	// end of for C
	}	// end of for R

	for (int t = 0; t < T; t++) {
		dust_spread();
		turn_dust(up_dust);
		turn_dust(under_dust);
	}	// end of for time

	int res = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			res += m[i][j];
		}
	}

	cout << res + 2 << "\n";		// 공기 청정기 두 군데이므로 + 2
	return 0;
}