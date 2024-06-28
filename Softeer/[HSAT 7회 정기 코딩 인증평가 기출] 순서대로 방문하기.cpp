#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int N, M, res;
int a[5][5], visited[5][5];
vector<pair<int, int>> v;

void dfs(pair<int, int> pos, int idx) {
	if (pos == v[idx]) {
		if (idx == M - 1) {
			res++;
			return;
		}
		idx++;
	}

	int r = pos.first;
	int c = pos.second;

	visited[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (visited[nr][nc]) continue;
		if (a[nr][nc]) continue;
		dfs({ nr, nc }, idx);
	}
	visited[r][c] = 0;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c;
		v.push_back({ --r, --c });
	}

	dfs(v[0], 1);
	cout << res << '\n';
	return 0;
}