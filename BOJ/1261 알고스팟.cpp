#include<cstdio>
#include<queue>
#include<algorithm>
#define INF 1e9
using namespace std;

int map[100][100];
int N, M;
int d[100][100];				// �� ��� �ν����� �ּҰ� ����
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void bfs(int r, int c) {
	
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, { r, c } });
	d[r][c] = 0;

	while (!q.empty()) {
		int r = q.front().second.first;		
		int c = q.front().second.second;
		int dist = q.front().first;
		q.pop();

		if (dist > d[r][c]) continue;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (0 <= nr && nr < N && 0 <= nc && nc < M) {
				if (map[nr][nc] == 1) {					// �� �Ʒ� ���� &&�� ���� ���� �޸� �ʰ� ��
					if (d[nr][nc] > d[r][c] + 1) {		// 1 �̹Ƿ� �� �ѹ� �� �μ����� + 1���� �۰ų� ������ �ǹ� ����
						d[nr][nc] = d[r][c] + 1;
						q.push({ d[r][c] + 1, { nr, nc } });
					}
				}
				else {
					if (d[nr][nc] > d[r][c]) {		// 0�̹Ƿ� �� ����. �̵��ϱ� �� ���� ����
						d[nr][nc] = d[r][c];
						q.push({ d[r][c], { nr, nc } });
					}
				}
			}

			/*
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (map[nr][nc] == 1) {
				if (d[nr][nc] > d[r][c] + 1) {
					d[nr][nc] = d[r][c] + 1;
					q.push({ d[r][c] + 1, { nr, nc } });
				}
			}
			else {
				if (d[nr][nc] > d[r][c]) {
					d[nr][nc] = d[r][c];
					q.push({ d[r][c], { nr, nc } });
				}
			}
			*/	
			/*												// �̰� �޸� �ʰ���
			if (0 <= nr && nr < N && 0 <= nc && nc < M) {
				if (map[nr][nc] == 0 && d[r][c] < d[nr][nc]) {
					d[nr][nc] = d[r][c];
					q.push({ d[r][c], { nr, nc } });
				}
				else if (map[nr][nc] == 1 && d[r][c] < d[nr][nc]){
					d[nr][nc] = d[r][c] + 1;
					q.push({ d[r][c] + 1, { nr, nc } });
				}
			}
			*/
		}			
	}

}

int main() {
	
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {		// �Ÿ��� �������� ��Ƽ� �ּҰ� ���
		fill(d[i], d[i] + M, INF);
	}

	bfs(0, 0);

	printf("%d\n", d[N - 1][M - 1]);
}