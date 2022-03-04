#include<iostream>
#include<string>
#define MAXR 10000
#define MAXC 500
using namespace std;

int R, C;
char map[MAXR][MAXC];
bool visited[MAXR][MAXC];
int dr[] = { -1, 0, 1 };		// ���� �밢, ����, �Ʒ� �밢 ������ ��
int dc[] = { 1, 1, 1 };			// ���������� Ȯ���ϱ� ������ �Ʒ��� �����ϴ°� ���ٴ� ���� �����ؾ� �ϳ��� �� Ȯ�� �����ϴٰ� �Ǵ�

bool dfs(int r, int c) {
	visited[r][c] = true;

	if (c == C - 1) return true;	// ������ true ����

	for (int i = 0; i < 3; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= R || nc >= C || visited[nr][nc] ) continue;	// ����ų� �̹� ������ ��� ����
		if (map[nr][nc] == '.') {
			if (dfs(nr, nc)) return true;			// ���⼭ true�� �Ȱ������� ���� true�� ��ȯ �ȵǱ� ������ true�� �ѹ� �߸� ��� ��������
		}											// false�� �������� �ٸ� ��� Ȯ�ε� ���ϰ� false �� �ǹǷ� ����
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) {
			map[i][j] = input[j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < R; i++) {				// �� ���� Ȯ���غ���
		if (dfs(i, 0)) {
			cnt++;
		}
	}
	cout << cnt << "\n";
}