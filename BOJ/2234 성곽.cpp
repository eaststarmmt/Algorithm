#include<iostream>
#include<cstring>
#include<queue>
#define endl "\n"
using namespace std;

int map[50][50];
bool visited[50][50];
int R, C;
int dr[] = { 0, -1, 0, 1 };	// 서 북 동 남 순서로
int dc[] = { -1, 0, 1, 0 };

class Pos {
public:
	int r, c;
	Pos(int r, int c) {
		this->r = r;
		this->c = c;
	}
};

int bfs(int r, int c) {
	queue<Pos> Q;
	Q.push(Pos(r, c));
	visited[r][c] = true;
	int width = 1;
	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		Q.pop();

		int wall = 1;					
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < R && nc < C && !visited[nr][nc] && (wall & ~map[r][c]) != 0) {	// 벽이 있는지 없는지 비트연산으로 확인
				Q.push(Pos(nr, nc));
				visited[nr][nc] = true;
				width++;
			}
			wall <<= 1;	// 다음 방향의 벽을 확인하기 위해 shift
		}
	}
	return width;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C >> R;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 0;	// 방의 개수
	int maxWidth = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j]) {
				cnt++;
				int width = bfs(i, j);
				maxWidth = width > maxWidth ? width : maxWidth;
			}
		}
	}
	cout << cnt << endl << maxWidth << endl;	// maxWidth 굳이 초기화 안해도 더 커질것이므로 진행
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 1; k < 16; k <<= 1) {	// 해당 좌표에서 벽 하나씩 없애보기
				if ((map[i][j] & k) != 0) {		// 벽이 있다면 벽 없애고 진행
					map[i][j] -= k;		// 벽 없애기
					memset(visited, false, sizeof(visited));
					int width = bfs(i, j);
					maxWidth = width > maxWidth ? width : maxWidth;
					map[i][j] += k;		// 벽 다시 복구
				}
			}
		}
	}
	cout << maxWidth << endl;
}