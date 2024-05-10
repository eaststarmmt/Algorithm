#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int R, C, res;
int a[8][8], visited[8][8];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

vector<pair<int, int>> v;	// 빈 칸을 넣어놓을 리스트
queue<pair<int, int>> temp;

void bfs() {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> Q = temp;

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if (visited[nr][nc]) continue;
			if (a[nr][nc]) continue;	// 빈칸으로만 불이 퍼질 수 있음
			Q.push({ nr, nc });
			visited[nr][nc] = 1;
		}	// end of for
	}	// end of while
}

int count() {
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			// 방문 했으면 불이 퍼지는 위치
			if (a[i][j] == 0  && !visited[i][j]) cnt++;
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) v.push_back({ i, j });
			else if (a[i][j] == 2) temp.push({ i, j });
		}	// end of for j
	}	// end of for i

	for (int i = 0; i < v.size() - 2; i++) {
		a[v[i].first][v[i].second] = 1;
		for (int j = i + 1; j < v.size() - 1; j++) {
			a[v[j].first][v[j].second] = 1;
			for (int k = j + 1; k < v.size(); k++) {
				a[v[k].first][v[k].second] = 1;
				bfs();
				res = max(res, count());
				a[v[k].first][v[k].second] = 0;
			}
			a[v[j].first][v[j].second] = 0;
		}	// end of for j
		a[v[i].first][v[i].second] = 0;
	}	// end of for i

	cout << res << '\n';
}