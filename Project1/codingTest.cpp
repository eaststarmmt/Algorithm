#include<cstdio>
#include<queue>
#include<algorithm>
#define INF 1e9
using namespace std;

int map[100][100];
int N, M;
int d[100][100];				// 벽 몇번 부쉈는지 최소값 저장
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
				if (map[nr][nc] == 1) {					// 위 아래 조건 &&로 묶어 쓰면 메모리 초과 남
					if (d[nr][nc] > d[r][c] + 1) {		// 1 이므로 벽 한번 더 부술예정 + 1보다 작거나 같으면 의미 없음
						d[nr][nc] = d[r][c] + 1;
						q.push({ d[r][c] + 1, { nr, nc } });
					}
				}
				else {
					if (d[nr][nc] > d[r][c]) {		// 0이므로 벽 없음. 이동하기 전 값과 같음
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
			/*												// 이건 메모리 초과남
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
	
	for (int i = 0; i < N; i++) {		// 거리를 무한으로 잡아서 최소값 계산
		fill(d[i], d[i] + M, INF);
	}

	bfs(0, 0);

	printf("%d\n", d[N - 1][M - 1]);
}