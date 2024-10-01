#include<iostream>
#include<algorithm>

using namespace std;

int R, M, C, res = -1;
int a[34][14];  // 유실선은 1로 표시

void print() {
	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

int check() {
	for (int j = 1; j <= C; j++) {
		int c = j;
		for (int i = 1; i <= R; i++) {
			// 좌우 유실선 있는지 확인
			int left = a[i][c - 1];
			int right = a[i][c];

			if (left) c--;
			if (right) c++;
		}
		if (c != j) return 0;    // 하나라도 틀리면 틀림
	}
	return 1;
}

void go(int start_r, int start_c, int cnt, int line) {
	if (res != -1) return;   // 답 나온 경우 불필요한 반복을 막기 위함
	if (cnt == line) {    // 유실선 다 채웠을 때
		if (check()) {
			res = cnt;
		}
		return;
	}

	// 다음줄로 이동해야 되는지 체크하는 로직
	int r = start_c > C ? start_r + 1 : start_r;
	int c = start_c > C ? 1 : start_c;
	for (; r <= R; r++) {
		for (; c <= C - 1; c++) {	// 끝에는 유실선을 긋지 못하므로 C - 1까지만
			if (a[r][c - 1] || a[r][c] || a[r][c + 1]) continue; // 선 겹치는지 확인. 크기 여유 있어서 범위 벗어나지 않음
			a[r][c] = 2;    // 유실선 표시
			go(r, c + 1, cnt + 1, line);
			a[r][c] = 0;    // 표시 해제
		}   // end of for j
		c = 1;  // C 값 처음으로 돌아와야 됨. for문에서 하면 시작하는 지점을 표시하기가 힘들어서 따로 로직 처리
	}   // end of for i
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C >> M >> R;

	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c;
		r, c;
		a[r][c] = 1;  // 유실선 표시
	}   // end of for M

	if (check()) {   // 처음부터 버그 없는 경우
		cout << 0 << '\n';
		return 0;
	}


	for (int line = 1; line <= 3; line++) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C - 1; j++) {	// 끝에는 유실선을 긋지 못하므로 C - 1까지만
				if (a[i][j - 1] || a[i][j] || a[i][j + 1]) continue; // 선 겹치는지 확인. 크기 여유 있어서 범위 벗어나지 않음
				a[i][j] = 2;    // 유실선 표시
				go(i, j + 1, 1, line);
				a[i][j] = 0;
			}   // end of for j
		}   // end of for i
		if (res != -1) break;    // 답 나왔으면 종료
	}

	cout << res << '\n';
}