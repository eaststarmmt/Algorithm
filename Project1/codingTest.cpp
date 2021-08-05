#include<stdio.h>
#include<algorithm>
using namespace std;

bool visited[50][50];							// �湮�ߴ��� Ȯ��
int map[50][50];								// �޾ƿ� ���� ����
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1 };		// 8�� Ž���� ���� ���� ������
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int w, h;

bool dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= h || y >= w) return false;
	if (visited[x][y]) return false;
	if (map[x][y] == 0) return false;
	visited[x][y] = true;
	
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(nx, ny);
	}
	return true;
	
}

int main() {
	while (1) {
		
		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < 50; i++) {
			fill(map[i], map[i] + 50, 0);
		}

		for (int i = 0; i < 50; i++) {
			fill(visited[i], visited[i] + 50, false);
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (dfs(i, j)) cnt++;		// true�� ������ ���̹Ƿ� ī����
			}
		}
		printf("%d\n", cnt);
	}	// end of while
}