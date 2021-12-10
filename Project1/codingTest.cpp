#include<iostream>
#define endl "\n"
using namespace std;

int anaSibal[][2] = {	// 도형 노가다로 위치 다 그려서 넣어놓기
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
	for (int i = 0; i < 19; i++) {	// 도형이 총 19 가지
		int sum = 0;
		bool flag = true;
		for (int j = i * 4; j < i * 4 + 4; j++) {	// 4개 단위로 끊어서 계산
			int nr = r + anaSibal[j][0];
			int nc = c + anaSibal[j][1];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C) {	// 범위 넘어가면 flag로 총값으로 넣지 말라고 표시하고 탈출
				flag = false;
				break;
			}
			sum += map[nr][nc];			// 해당 위치 맵 값 계속 더하기
		}
		if (flag) res = sum > res ? sum : res;	// 최대값 갱신
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