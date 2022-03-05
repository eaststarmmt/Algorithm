#include<iostream>
#define endl "\n"
using namespace std;

int map[50][50];
bool cleaning[50][50];
int dr[] = { -1, 0, 1, 0 };		// 북 동 남 서
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
	while (true) {	// 1. 현재 위치 청소. 
		if (!cleaning[r][c]) {
			cleaning[r][c] = true;
			cnt++;
		}
		bool flag = false;
		// 2. 왼쪽부터 차례대로 청소
		for (int i = 0; i < 4; i++) {
			dir = (dir + 3) % 4;	// 왼쪽 방향
			int nr = r + dr[dir];
			int nc = c + dc[dir];
			// 공간 있는지 확인부터
			if (nr >= 0 && nr < R && nc >= 0 && nc < C) {	// 공간이 있는 경우
				if (!cleaning[nr][nc] && map[nr][nc] == 0) {	// a. 청소가 가능한 경우
					r = nr;
					c = nc;
					flag = true;
					break;
				}
			}
		}
		
		if (!flag) {	// 네방향 모두 확인한 경우
			int nr = r - dr[dir];
			int nc = c - dc[dir];
			
			if (nr >= 0 && nr < R && nc >= 0 && nc < C) {	// 뒤에 공간 있는지
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