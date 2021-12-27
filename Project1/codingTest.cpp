#include<cstdio>
#include<queue>
#define endl "\n"
using namespace std;

struct Info {
	int r, c, time, wall;
};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int map[1000][1000];
bool visited[1000][1000][10];	// �� 10������ �μ��� ����
int R, C, K;
int res;

void bfs() {
	queue<Info> Q;
	Q.push({ 0, 0, 1, 0 });	// �����ϴ� ĭ�� ������ ĭ �����ؾ� �ǹǷ�
	visited[0][0][0] = true;

	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		int time = Q.front().time;
		int wall = Q.front().wall;
		Q.pop();

		if (r == R - 1 && c == C - 1) {	// ������ ���� ��
			printf("%d\n", time);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr < R && nc >= 0 && nc < C) {	
				if (!visited[nr][nc][wall]) {	
					if (map[nr][nc] == 0) {		// �� �μ� �ʿ� ���� ���
						visited[nr][nc][wall] = true;
						Q.push({ nr, nc, time + 1, wall });
					}
					else if (map[nr][nc] == 1 && wall < K && !visited[nr][nc][wall + 1]) {	// �� �ν��� �Ǵ� ���. ���� K�� �Ⱥν�����
						visited[nr][nc][wall + 1] = true;
						Q.push({ nr, nc, time + 1, wall + 1 });
					}
				}
			}
		}
	}
	printf("-1\n");		// ť�� �������� ������ �� ���ٴ� ��
}

int main() {
	scanf("%d %d %d", &R, &C, &K);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%1d", &map[i][j]);
		}
	}	// end of input

	bfs();
}