#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

struct Info {
	int r, c, s;
};

int R, C, K;
int _map[54][54], temp[54][54], visited[54][54];
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
vector<Info> info;
vector<int> idx_v;
vector<pair<int, int>> rot_v;
int res = INF;
int dir, sr, sc, er, ec;

void set_rot(int r, int c, int flag) {	// 처음에는 무조건 모서리에서 시작하는데 방향 바꾸면 안되기 때문에 flag 사용
	// 모서리에 가면 방향 변경.
	if (!flag && r == sr && c == sc) dir++;
	if (!flag && r == sr && c == ec) dir++;
	if (!flag && r == er && c == sc) dir++;
	if (!flag && r == er && c == ec) dir++;

	int nr = r + dr[dir];
	int nc = c + dc[dir];

	if (visited[nr][nc]) return;	// 이미 담았으면 종료

	visited[nr][nc] = 1;
	rot_v.push_back({ nr, nc });	// 회전시킬 위치 벡터에 저장
	set_rot(nr, nc, 0);
}

void rot() {
	vector<int> rot_val;
	// 원래 값 저장
	for (int i = 0; i < rot_v.size(); i++) {
		rot_val.push_back(temp[rot_v[i].first][rot_v[i].second]);
	}	// end of for

	rotate(rot_val.begin(), rot_val.begin() + rot_val.size() - 1, rot_val.end());
	// 회전시킨 값 맵에 저장
	for (int i = 0; i < rot_v.size(); i++) {
		temp[rot_v[i].first][rot_v[i].second] = rot_val[i];
	}	// end of for
}

void pre_rot(int r, int c, int s) {	// r, c 는 중심 s는 몇둘레 회전하는지.
	for (int i = 1; i <= s; i++) {	// 한 둘레씩 따로 빼서 회전시킨 후 저장하는 방식
		sr = r - i;		// 모서리 잡기
		sc = c - i;
		er = r + i;
		ec = c + i;

		memset(visited, 0, sizeof(visited));
		rot_v.clear();
		dir = 0;	//방향 초기화

		visited[sr][sc] = 1;
		rot_v.push_back({ sr, sc });	// 회전시킬 위치 벡터에 저장
		set_rot(sr, sc, 1);

		rot();
	}
}

int solve() {
	for (int i : idx_v) {
		pre_rot(info[i].r, info[i].c, info[i].s);
	}	// end of for idx_v
	int min_val = INF;
	for (int i = 0; i < R; i++) {
		int row = 0;
		for (int j = 0; j < C; j++) {
			row += temp[i][j];
		}
		min_val = min(row, min_val);
	}
	return min_val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> _map[i][j];
		}	// end of for R
	}	// end of for C

	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		info.push_back({ --r, --c, s });	// 맵을 0,0부터 시작하기 위함
		idx_v.push_back(i);
	}	// end of for K

	do {
		memcpy(temp, _map, sizeof(temp));	// 처음 상태의 맵으로 돌려야 됨
		res = min(res, solve());
	} while (next_permutation(idx_v.begin(), idx_v.end()));

	cout << res << "\n";

	return 0;
}