#include<iostream>
#define endl "\n"
using namespace std;

int anaSibal[][2] = {	// ���� �밡�ٷ� ��ġ �� �׷��� �־����
	{0, 0}, {0, 1}, {0, 2}, {0, 3},
	{0, 0}, {1, 0}, {2, 0}, {3, 0},

	{0, 0}, {0, 1}, {1, 0}, {1, 1},

	{0, 0}, {1, 0}, {2, 0}, {2, 1},
	{0, 0}, {0, 1}, {0, 2}, {1, 0},
	{0, 0}, {0, 1}, {1, 1}, {2, 1},
	{1, 0}, {1, 1}, {1, 2}, {0, 2},

	{2, 0}, {2, 1}, {1, 1}, {0, 1},
	{0, 0}, {0, 1}, {0, 2}, {1, 2},
	{0, 0}, {1, 0}, {2, 0}, {0, 1},
	{0, 0}, {1, 0}, {1, 1}, {1, 2},

	{0, 0}, {1, 0}, {1, 1}, {2, 1},
	{1, 0}, {1, 1}, {0, 1}, {0, 2},
	{0, 0}, {0, 1}, {1, 1}, {1, 2},
	{2, 0}, {1, 0}, {1, 1}, {0, 1},

	{0, 1}, {1, 0}, {1, 1}, {1, 2},
	{0, 0}, {1, 0}, {2, 0}, {1, 1},
	{0, 0}, {0, 1}, {0, 2}, {1, 1},
	{1, 0}, {0, 1}, {1, 1}, {2, 1},
};
int R, C, res;
int map[500][500];

void check(int r, int c) {
	for (int i = 0; i < 19; i++) {	// ������ �� 19 ����
		int sum = 0;
		bool flag = true;
		for (int j = i * 4; j < i * 4 + 4; j++) {	// 4�� ������ ��� ���
			int nr = r + anaSibal[j][0];
			int nc = c + anaSibal[j][1];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C) {	// ���� �Ѿ�� flag�� �Ѱ����� ���� ����� ǥ���ϰ� Ż��
				flag = false;
				break;
			}
			sum += map[nr][nc];			// �ش� ��ġ �� �� ��� ���ϱ�
		}
		if (flag) res = sum > res ? sum : res;	// �ִ밪 ����
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}	// end of input

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			check(i, j);
		}
	}

	cout << res << endl;
}