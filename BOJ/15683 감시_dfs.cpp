#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
int a[10][10];
int R, C, res = INF;
vector<pair<int, int>> cctv;

void observe(vector<pair<int, int>>& ob, int d, int here) {
	d %= 4;
	int r = cctv[here].first;	// cctv 위치 저장
	int c = cctv[here].second;

	while (1) {
		r += dr[d];		// 방향에 맞게 계속 이동
		c += dc[d];

		if (r < 0 || r >= R || c < 0 || c >= C || a[r][c] == 6) break;	// 맵 벗어나거나 벽이면 종료
		if (a[r][c]) continue;	// 0이 아니면 이미 표시 된 지점이거나 cctv 이므로 무시

		ob.push_back({ r, c });	// 바꾼 지점 저장
		a[r][c] = -1;			// cctv 감시 지점 마킹
	}	// end of while

	return;
}

vector<pair<int, int>> check(int here, int d) {
	vector<pair<int, int>> ob;	// 감시하는 곳 위치 저장
	observe(ob, d, here);	// 기본 방향 감시 표시
	int num = a[cctv[here].first][cctv[here].second];	// cctv 번호. 

	// cctv 번호별로 필요한 부분 추가 표시
	if (num == 2) {
		observe(ob, d + 2, here);	// 반대 방향 감시 표시.
	}
	else if (num == 3) {
		observe(ob, d + 1, here);
	}
	else if (num == 4) {
		observe(ob, d + 1, here);
		observe(ob, d + 2, here);
	}
	else if (num == 5) {
		observe(ob, d + 1, here);
		observe(ob, d + 2, here);
		observe(ob, d + 3, here);
	}

	return ob;
}

void dfs(int here) {
	if (here == cctv.size()) {	// cctv 설정 끝난 다음에 사각지대 카운팅
		int cnt = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (a[i][j] == 0) cnt++;
			}	// end of for j
		}	// end of for i
		res = min(res, cnt);
		return;
	}

	for (int i = 0; i < 4; i++) {	// 4방향 돌려봐야 됨
		vector<pair<int, int>> reset = check(here, i);	// cctv 감시 표시 하려고 바꿔놓은 값 다시 돌리기 위해 저장
		dfs(here + 1);
		for (pair<int, int> p : reset) {	// cctv 표시 하기 전으로 원복
			a[p.first][p.second] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0 && a[i][j] != 6) {	// cctv 위치 저장
				cctv.push_back({ i, j });
			}
		}	// end of for j
	}	// end of for i

	dfs(0);

	cout << res << "\n";

	return 0;
}