#include<cstdio>
#define MAX 500
using namespace std;

bool visited[MAX][MAX];
int map[MAX][MAX];
int N, M, cnt, picture, maxCnt;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void dfs(int r, int c) {
	visited[r][c] = true;	// �湮 ó��
	cnt++;				// cnt ����

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 0 && nc >= 0 && nr < N && nc < M && !visited[nr][nc] && map[nr][nc] == 1) {
			dfs(nr, nc);	// �湮 ���߰� 1�̸� �湮
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && map[i][j] == 1) {		// �湮 ���߰� 1�ΰ��� ������ �׸� �� �� ����
				dfs(i, j);
				picture++;							// �׸� ī����
				maxCnt = cnt > maxCnt ? cnt : maxCnt;	// ���� ���� �׸� ����
				cnt = 0;		// cnt �ʱ�ȭ
			}
		}
	}

	printf("%d\n%d\n", picture, maxCnt);
}