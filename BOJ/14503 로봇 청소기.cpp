#include<iostream>
#define endl "\n"
using namespace std;

int map[50][50];
bool cleaning[50][50];
int dr[] = { -1, 0, 1, 0 };		// �� �� �� ��
int dc[] = { 0, 1, 0, -1 };
int R, C;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> R >> C;
	int r, c, dir;
	cin >> r >> c >> dir;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}	// end of input
	int cnt = 0;
	while (true) {	// 1. ���� ��ġ û��. 
		if (!cleaning[r][c]) {
			cleaning[r][c] = true;
			cnt++;
		}
		bool flag = false;
		// 2. ���ʺ��� ���ʴ�� û��
		for (int i = 0; i < 4; i++) {
			dir = (dir + 3) % 4;	// ���� ����
			int nr = r + dr[dir];
			int nc = c + dc[dir];
			// ���� �ִ��� Ȯ�κ���
			if (nr >= 0 && nr < R && nc >= 0 && nc < C) {	// ������ �ִ� ���
				if (!cleaning[nr][nc] && map[nr][nc] == 0) {	// a. û�Ұ� ������ ���
					r = nr;
					c = nc;
					flag = true;
					break;
				}
			}
		}
		
		if (!flag) {	// �׹��� ��� Ȯ���� ���
			int nr = r - dr[dir];
			int nc = c - dc[dir];
			
			if (nr >= 0 && nr < R && nc >= 0 && nc < C) {	// �ڿ� ���� �ִ���
				if (map[nr][nc] == 0) {
					r = nr;
					c = nc;
					continue;
				}
				else {
					cout << cnt << endl; 
					return 0;
				}
			}
		}
	}
}