#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
int R, C, res;
int a[204][204], visited[204][204];

bool check_range(int r, int c) {	// 범위 벗어나는지 체크
	if (r < 0 || r >= R || c < 0 || c >= C) return false;
	return true;
}

void dfs(int r, int c, int sum, int cnt) {
	if (cnt == 4) {		// 네칸 이동한 경우
		res = max(sum, res);
		return;
	}

	visited[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (!check_range(nr, nc)) continue;
		if (visited[nr][nc]) continue;
		dfs(nr, nc, sum + a[nr][nc], cnt + 1);
	}

	visited[r][c] = 0;
}

void check_t(int r, int c) {	// T ㅗ 모양 확인
	for (int i = 0; i < 4; i++) {
		int sum = a[r][c];
		for (int j = i; j < i + 3; j++) {
			int nr = r + dr[j % 4];
			int nc = c + dc[j % 4];
			// 범위 벗어났으면 현재 케이스는 최댓값 갱신에 영향을 주면 안됨
			if (!check_range(nr, nc)) {
				sum = -1;
				break;
			}
			
			sum += a[nr][nc];
		}
		res = max(res, sum);
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
		}	// end of for j
	}	// end of for i

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			dfs(i, j, a[i][j], 1);
			check_t(i, j);
		}
	}
	cout << res << '\n';
}