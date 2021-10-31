#include<iostream>
#include<cstring>
#include<queue>
#define endl "\n"
using namespace std;

int map[50][50];
bool visited[50][50];
int R, C;
int dr[] = { 0, -1, 0, 1 };	// �� �� �� �� ������
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
			if (nr >= 0 && nc >= 0 && nr < R && nc < C && !visited[nr][nc] && (wall & ~map[r][c]) != 0) {	// ���� �ִ��� ������ ��Ʈ�������� Ȯ��
				Q.push(Pos(nr, nc));
				visited[nr][nc] = true;
				width++;
			}
			wall <<= 1;	// ���� ������ ���� Ȯ���ϱ� ���� shift
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

	int cnt = 0;	// ���� ����
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
	cout << cnt << endl << maxWidth << endl;	// maxWidth ���� �ʱ�ȭ ���ص� �� Ŀ�����̹Ƿ� ����
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 1; k < 16; k <<= 1) {	// �ش� ��ǥ���� �� �ϳ��� ���ֺ���
				if ((map[i][j] & k) != 0) {		// ���� �ִٸ� �� ���ְ� ����
					map[i][j] -= k;		// �� ���ֱ�
					memset(visited, false, sizeof(visited));
					int width = bfs(i, j);
					maxWidth = width > maxWidth ? width : maxWidth;
					map[i][j] += k;		// �� �ٽ� ����
				}
			}
		}
	}
	cout << maxWidth << endl;
}