#include<iostream>
#include<queue>
#define endl "\n"
using namespace std;

int N, M;
bool visited[100][70];
int map[100][70];
int dr[] = { -1, 1, 0, 0, -1, -1, 1, 1 };	// 8�� Ž��
int dc[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
bool peek;
void dfs(int r, int c) {
	for (int i = 0; i < 8; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
			if (map[nr][nc] > map[r][c]) peek = false;	// �� ������ ������ �Ұ���
			if (visited[nr][nc] || map[r][c] != map[nr][nc]) continue;	// �湮 �߰ų� �� �ٸ��� ����
			visited[nr][nc] = true;
			dfs(nr, nc);

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

		}
	}	// end of input

	int res = 0;	// ����츮 ī����

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				peek = true;
				dfs(i, j);
				if (peek) res++;
			}

		}
	}
	cout << res << endl;
}