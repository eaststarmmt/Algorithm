#include<iostream>
#include<string>
using namespace std;

char map[20][20];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int test = 1; test <= T; test++) {

		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string input;
			cin >> input;
			for (int j = 0; j < N; j++) {
				map[i][j] = input[j];
			}
		}
		int cnt = 0;
		bool flag = false;
		for (int i = 0; i < N; i++) {		// 가로줄 확인
			if (flag) break;
			cnt = 0;
			for (int j = 0; j < N; j++) {
				if (map[i][j] != '.') cnt++;
				else cnt = 0;
				if (cnt == 5) {
					flag = true;
					break;
				}
			}
			
		}		

		for (int i = 0; i < N; i++) {		// 세로줄 확인
			if (flag) break;
			cnt = 0;
			for (int j = 0; j < N; j++) {
				if (map[j][i] != '.') cnt++;
				else cnt = 0;
				if (cnt == 5) {
					flag = true;
					break;
				}
			}
		}

		for (int i = 0; i < N; i++) {		// 대각 오른쪽 아래방향 확인
			if (flag) break;
			for (int j = 0; j < N; j++) {
				cnt = 0;
				for (int r = i, c = j; r < N && c < N; r++, c++) {
					if (map[r][c] != '.') cnt++;
					else cnt = 0;
					if (cnt == 5) {
						flag = true;
						break;
					}
				}
				
			}
		}

		for (int i = N - 1; i >= 0; i--) {		// 대각 왼쪽 위 방향 확인
			if (flag) break;
			for (int j = 0; j < N; j++) {
				cnt = 0;
				for (int r = i, c = j; r >= 0 && c < N; r--, c++) {
					if (map[r][c] != '.') cnt++;
					else cnt = 0;
					if (cnt == 5) {
						flag = true;
						break;
					}
				}
			}
		}

		if (flag) cout << "#" << test << " YES\n";
		else cout << "#" << test << " NO\n";
	}
}

/*

4
5
....o
...o.
..o..
.o...
o....
5
...o.
ooooo
...o.
...o.
.....
5
.o.oo
oo.oo
.oo..
.o...
.o...
5
.o.o.
o.o.o
.o.o.
o.o.o
.o.o.
*/