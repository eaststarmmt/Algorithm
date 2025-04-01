#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, output, r, c;
int a[24][24], visited[24][24], temp[6], dice[6] = { 5, 4, 1, 3, 2, 6 };
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

int get_dir(int d) {
	// 주사위 아랫면과 비교
	int dir = d;
	if (dice[5] > a[r][c]) dir = (dir + 1) % 4;
	else if (dice[5] < a[r][c]) dir = (dir + 3) % 4;

	// 보드 넘어가는지 체크
	int nr = r + dr[dir];
	int nc = c + dc[dir];

	if (nr < 0 || nr >= N || nc < 0 || nc >= N) dir = (dir + 2) % 4;

	return dir;
}

void move(int d) {
	// 좌표 이동
	r += dr[d];
	c += dc[d];

	// 주사위 이동에 따른 전개도
	memcpy(temp, dice, sizeof(dice));

	switch (d) {
	case 0:
		dice[1] = temp[5];
		dice[5] = temp[3];
		dice[3] = temp[2];
		dice[2] = temp[1];
		break;
	case 1:
		dice[0] = temp[5];
		dice[5] = temp[4];
		dice[4] = temp[2];
		dice[2] = temp[0];
		break;
	case 2:
		dice[1] = temp[2];
		dice[2] = temp[3];
		dice[3] = temp[5];
		dice[5] = temp[1];
		break;
	case 3:
		dice[0] = temp[2];
		dice[2] = temp[4];
		dice[4] = temp[5];
		dice[5] = temp[0];
		break;
	}

}

int dfs(int cur_r, int cur_c) {
	visited[cur_r][cur_c] = 1;
	int cur = a[cur_r][cur_c];
	int res = cur;
	for (int i = 0; i < 4; i++) {
		int nr = cur_r + dr[i];
		int nc = cur_c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (a[nr][nc] != cur) continue;
		if (visited[nr][nc]) continue;
		
		res += dfs(nr, nc);
	}	// end of for
	return res;
}

int get_score() {
	int res = 0;
	memset(visited, 0, sizeof(visited));
	
	res = dfs(r, c);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}   // end of for

	int cnt = M;
	int dir = 0;

	while (cnt--) {
		if (cnt + 1 != M) {
			dir = get_dir(dir);
		}
		move(dir);
		output += get_score();
	}   // end of while

	cout << output << '\n';

	return 0;
}