#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Corner {
	int r, c;
};
int map[21][21];
int border[21][21];
int population[5];
int ans = 1e9;
int N;
Corner corner[4];
bool check(int& x, int& y, int& d1, int& d2) {
	if (x + d1 + d2 > N) return false;
	if (y - d1 < 1) return false;
	if (y + d2 > N) return false;
	return true;
}

void calc() {
	memset(population, 0, sizeof(population));	// 인구 다 0으로 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			population[border[i][j] - 1] += map[i][j];
		}
	}	// end of calc population
	sort(population, population + 5);
	int dif = population[4] - population[0];
	ans = dif < ans ? dif : ans;
}

void border_setting(int& x, int& y, int& d1, int& d2) {
	for (int r = 1; r <= N; r++) {	// 구역 다 5로 초기화
		fill(border[r] + 1, border[r] + N + 1, 5);
	}	// end of border init
	
	// 1번 선거구 표시
	int cnt = 0;	// 대각으로 경계가 있어서 내려갈 때마다 하나씩 줄거나 늘어남. 변하는 시점 잘 파악해야 됨
	for (int r = 1; r < corner[1].r; r++) {
		if (r >= corner[0].r) cnt++;
		for (int c = 1; c <= corner[0].c - cnt; c++) {
			border[r][c] = 1;
		}
	}

	// 2번 선거구 표시
	cnt = 0;
	for (int r = 1; r <= corner[2].r; r++) {
		if (r > corner[0].r) cnt++;
		for (int c = corner[0].c + 1 + cnt; c <= N; c++) {	// 대각 시작 시점이 오른쪽으로 밀림
			border[r][c] = 2;
		}
	}

	// 3번 선거구 표시
	cnt = 0;
	for(int r = N; r >= corner[1].r; r--) {
		if (r < corner[3].r) cnt++;
		for (int c = 1; c < corner[3].c - cnt; c++) {
			border[r][c] = 3;
		}
	}

	// 4번 선거구 표시
	cnt = 0;
	for (int r = N; r > corner[2].r; r--) {
		if (r <= corner[3].r) cnt++;
		for (int c = corner[3].c + cnt; c <= N; c++) {
			border[r][c] = 4;
		}
	}
	calc();
}

void select_length() {
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N - x; d1++) {
				for (int d2 = 1; d2 <= N - y; d2++) {
					if (check(x, y, d1, d2)) {
						corner[0] = { x, y };	// 위
						corner[1] = { x + d1, y - d1 }; // 왼쪽
						corner[2] = { x + d2, y + d2 };	// 오른쪽
						corner[3] = { x + d1 + d2, y - d1 + d2 };	// 아래
						border_setting(x, y, d1, d2);
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}	// end of for map input
	
	select_length();
	printf("%d\n", ans);
}