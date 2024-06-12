#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int R, C, start_r, start_c;
int a[1004][1004], visited[1004][1004];

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (i == start_r && j == start_c) cout << 0;
			else if (!a[i][j]) cout << 0;
			else if (!visited[i][j]) cout << -1;
			else cout << visited[i][j] - 1;
			cout << ' ';
		}	// end of for j
		cout << '\n';
	}	// end of for i
}

void bfs() {
	queue<pair<int, int>> Q;
	Q.push({ start_r, start_c });
	visited[start_r][start_c] = 1;

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if (visited[nr][nc]) continue;
			if (!a[nr][nc]) continue;

			Q.push({ nr, nc });
			visited[nr][nc] = visited[r][c] + 1;
		}	// end of for i
	}	// end of while
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				start_r = i;
				start_c = j;
			}
		}	// end of for j
	}	// end of for i

	bfs();
	print();

}