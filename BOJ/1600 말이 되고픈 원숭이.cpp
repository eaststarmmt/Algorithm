#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int map[200][200];
bool visited[200][200][31];					// visited�� K�� ���� ī���ÿ� ���� ��찡 �޶����Ƿ� ���� ���� ��
int dr[12] = { -1, 1, 0, 0, -1, -2, -2, -1, 1, 2, 2, 1 };
int dc[12] = { 0, 0, -1, 1, -2, -1, 1, 2, 2, 1, -1, -2 };
int K, W, H;

int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> queue;
	queue.push({ {0, K}, {0, 0} });
	visited[0][0][K] = true;
	int minCnt = -1;
	while (!queue.empty()) {
		int cnt = queue.front().first.first;
		int kCount = queue.front().first.second;
		int r = queue.front().second.first;
		int c = queue.front().second.second;

		if (r == H - 1 && c == W - 1) {
			minCnt = cnt;
			return cnt;
		}

		queue.pop();

		for (int i = 0; i < 4; i++) {		// ������ ĭ�� ���� ���

			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < H && nc < W && map[nr][nc] == 0 && !visited[nr][nc][kCount]) {
				queue.push({ {cnt + 1, kCount}, {nr, nc} });
				visited[nr][nc][kCount] = true;
			}
		}
		if (kCount == 0) continue;

		for (int i = 4; i < 12; i++) {		// ��ó�� �ٴ� ���
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < H && nc < W && map[nr][nc] == 0 && !visited[nr][nc][kCount - 1]) {
				queue.push({ {cnt + 1, kCount - 1}, {nr, nc} });
				visited[nr][nc][kCount - 1] = true;
			}
		}
	}
	return minCnt;
}

int main() {
	scanf("%d", &K);

	scanf("%d %d", &W, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", bfs());
}