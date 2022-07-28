#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int N, L, R;
int map[54][54];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
bool visited[54][54];

vector<pair<int, int>> pop_move;

void dfs(int r, int c) {
	visited[r][c] = true;
	pop_move.push_back({ r, c });
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (visited[nr][nc]) continue;
		int dif = abs(map[nr][nc] - map[r][c]);
		if (dif >= L && dif <= R) {
			dfs(nr, nc);
		}
	}	// end of for
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	bool flag = true;
	int res = 0;
	while (flag) {
		flag = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					pop_move.clear();
					dfs(i, j);
					if (pop_move.size() > 1) {
						flag = true;
					}
					int sum = 0;
					for (pair<int, int> x : pop_move) {
						sum += map[x.first][x.second];
					}	// end of for move
					sum /= pop_move.size();
					for (pair<int, int> x : pop_move) {
						map[x.first][x.second] = sum;
					}	// end of for move
				}
			}	// end of for i
		}	// end of for j
		if (flag) res++;

	}	// end of while

	cout << res << "\n";
	return 0;
}