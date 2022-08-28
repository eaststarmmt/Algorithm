#include <iostream>
#include <algorithm>
using namespace std;

int R, C, res;
char map[24][24];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void dfs(int r, int c, int visited, int cnt) {
	res = max(cnt, res);	// �湮 ���� �ִ밪�� ����
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr <= 0 || nc <= 0 || nr > R || nc > C) continue;
		int next_bit = 1 << (map[nr][nc] - 'A');	// ���� ���� ���� ���ĺ� ��Ʈ ����
		if (next_bit & visited) continue;	// & ���� �� 0�� �ƴϸ� ���� ����
		dfs(nr, nc, visited | next_bit, cnt + 1);	// |�������� 1�� �ٲ� �� ���� ���� Ȯ��
	}	// end of for

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}	// end of for j
	}	// end of for i

	dfs(1, 1, 1 << (map[1][1] - 'A'), 1);
	cout << res << "\n";

	return 0;
}