#include<cstdio>
#include<vector>
using namespace std;
int dr[] = { 0, -1, 0, 1 };	// 방향 번호 그대로
int dc[] = { 1, 0, -1, 0 };
int map[101][101];
int N, c, r, d, g;
vector<int> save;

int countingSquare() {
	int cnt = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] == 1 && map[i][j + 1] && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)	// 선이 이어질 필요 없이 꼭지점만 맞으면 되는듯...
				cnt++;
		}
	}
	return cnt;
}

void dragonCurve() {		// 전 세대 방향들 뒤부터 + 1 해서 붙이면 됨
	int size = save.size();
	for (int i = size - 1; i >= 0; i--) {
		int d = (save[i] + 1) % 4;
		r += dr[d];
		c += dc[d];
		map[r][c] = 1;
		save.push_back(d);		// 다음 세대 계산을 위해 저장
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		save.clear();
		scanf("%d %d %d %d", &c, &r, &d, &g);
		map[r][c] = 1;
		r += dr[d];
		c += dc[d];
		map[r][c] = 1;	// 0세대 구현
		save.push_back(d);
		for (int j = 0; j < g; j++) {
			dragonCurve();
		}
	}
	printf("%d\n", countingSquare());
}