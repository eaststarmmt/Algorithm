#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

char map[101][101];
int R, C;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
bool visited[101][101];

void print() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
}

void downSkel(int r, int c) {
	memset(visited, false, sizeof(visited));
	vector<pair<int, int>> pos;
	queue<pair<int, int>> Q;
	pos.push_back({ r, c });
	visited[r][c] = true;
	Q.push({ r, c });
	int start = C, end = 0;
	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 1 && nr <= R && nc >= 1 && nc <= C && !visited[nr][nc] && map[nr][nc] == 'x') {
				Q.push({ nr, nc });
				visited[nr][nc] = true;
				pos.push_back({ nr, nc });
				start = nc < start ? nc : start;
				end = nc > end ? nc : end;
			}
		}
	}
	pair<int, int> bottom = { r, c };
	bool flag = false;
	// 제일 낮은 높이에서 가로로 쭉 내려서 가장 먼저 닿는곳 확인. 바닥 or 위로만 떨어진다고 했음
	
}

void skeleton(int r, int c) {
	for (int i = 0; i < 4; i ++ ) {
		if (i == 1) continue;
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (map[nr][nc] == 'x') {
			downSkel(nr, nc);
		}
	}
}

void stick(int index, int r) {
	// 막대기
	if (index % 2 != 0) {
		for (int c = 1; c <= C; c++) {
			if (map[r][c] != '.') {
				map[r][c] = '.';
				skeleton(r, c);
				break;
			}
		}
	}
	else {
		for (int c = C; c >= 1; c--) {
			if (map[r][c] != '.') {
				map[r][c] = '.';
				break;
			}
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= C; j++) {
			map[i][j] = s[j - 1];
		}
	}
	// 막대 던지기
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int h;	
		cin >> h;
		stick(i, h);
	}
	print();
}