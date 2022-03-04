#include<stdio.h>
#include<cstring>
using namespace std;

bool visited[50][50];
int map[50][50];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int M, N, K;
void dfs(int r, int c) {
	if (r < 0 || c < 0 || r >= M || c >= N) return;		// ������ ��� ��� ������
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!visited[nr][nc] && map[nr][nc] == 1)
			dfs(nr, nc);
	}

}

int main() {
	
	int T;
	scanf("%d", &T);

	for (int test = 0; test < T; test++) {

		scanf("%d %d %d", &M, &N, &K);

		for (int i = 0; i < K; i++) {		// ���� ��ġ �ޱ�
			
			int x, y;
			scanf("%d %d", &x, &y);
			map[x][y] = 1;		
		}

		int cnt = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && map[i][j] == 1) {		// �ð��� �Ƴ��� ���� ��� �������� ���ǿ� �´��� Ȯ��
					dfs(i, j);
					cnt++;				// ���ǿ� �¾����� ī����
				}
			}
		}
		printf("%d\n", cnt);
		if (test < T - 1) {					// ���������� �ʱ�ȭ�� �� �ʿ� ����
			memset(visited, false, sizeof(visited));
			memset(map, 0, sizeof(map));

		}

	}// end of for test
}