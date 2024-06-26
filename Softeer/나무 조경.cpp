#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, res;
int a[4][4], visited[4][4];
int dr[] = { 1, 0 };
int dc[] = { 0, 1 };

void comb(int cnt, int sum) {
	res = max(res, sum);

	if (cnt == 4) return;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			for (int k = 0; k < 2; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];

				if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
				if (visited[nr][nc]) continue;
				visited[nr][nc] = 1;
				comb(cnt + 1, sum + a[i][j] + a[nr][nc]);
				visited[nr][nc] = 0;

			}
			visited[i][j] = 0;
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}

	comb(0, 0);
	cout << res << '\n';
	return 0;
}