#include <bits/stdc++.h>
using namespace std;

int N, res;
struct Board {
	int _map[24][24];

	void move() {
		int temp[24][24];
		for (int i = 0; i < N; i++) {
			int c = -1;	// temp의 열을 세기 위한 변수
			int flag = 0;	// 0이 아닌 수가 c열에 들어 있는지 체크
			for (int j = 0; j < N; j++) {
				if (_map[i][j] == 0) {	// 값 0이면 무시
					continue;
				}
				if (flag && _map[i][j] == temp[i][c]) {	// flag 값이 1이고 map의 값과 temp의 값이 같은지. 같으면 합쳐지는 대상. 무조건 처음에는 flag가 0이라 c가 -1을 타지 않음
					temp[i][c] *= 2;
					flag = 0;	// 한번 합친거 또 합치지 않기 위해 0으로 표시. 0인데 temp에 값이 있으면 이미 합친것.
				}
				else {
					temp[i][++c] = _map[i][j];	// map의 값을 비어있는 temp에 저장
					flag = 1;	// temp에 값이 들어있음을 알리는 변수. 같으면 합쳐질 것이고 아니면 다시 여기 로직을 타서 다음 열에 저장될 것임
				}
			}	// end of for j

			for (c++; c < N; c++) {	// temp에 채워지지 않은 부분 0으로 채워줌. c 다음부터 채워야 해서 c++로 시작
				temp[i][c] = 0;
			}	// end of for c
		}	// end of for i
		memcpy(_map, temp, sizeof(_map));
	}

	void rotate_left() {	// 왼쪽으로 90도 회전. 회전시키면 한 방향만 구현해도 네방향 다 사용 가능
		int temp[24][24];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp[i][j] = _map[j][N - i - 1];
			}	// end of for j
		}	// end of for i
		memcpy(_map, temp, sizeof(_map));
	}

	int getMax() {
		int max_val = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				max_val = max(_map[i][j], max_val);
			}
		}
		return max_val;
	}
};

void comb(int cnt, Board now_board) {
	if (cnt == 5) {
		res = max(res, now_board.getMax());
		return;
	}

	for (int i = 0; i < 4; i++) {
		Board board = now_board;
		board.move();
		comb(cnt + 1, board);
		if (i == 3) return;
		now_board.rotate_left();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	Board board;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board._map[i][j];
		}	// end of for j
	}	// end of for i

	comb(0, board);

	cout << res << "\n";

	return 0;
}