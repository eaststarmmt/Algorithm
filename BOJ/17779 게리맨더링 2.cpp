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
	memset(population, 0, sizeof(population));	// �α� �� 0���� �ʱ�ȭ
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
	for (int r = 1; r <= N; r++) {	// ���� �� 5�� �ʱ�ȭ
		fill(border[r] + 1, border[r] + N + 1, 5);
	}	// end of border init
	
	// 1�� ���ű� ǥ��
	int cnt = 0;	// �밢���� ��谡 �־ ������ ������ �ϳ��� �ٰų� �þ. ���ϴ� ���� �� �ľ��ؾ� ��
	for (int r = 1; r < corner[1].r; r++) {
		if (r >= corner[0].r) cnt++;
		for (int c = 1; c <= corner[0].c - cnt; c++) {
			border[r][c] = 1;
		}
	}

	// 2�� ���ű� ǥ��
	cnt = 0;
	for (int r = 1; r <= corner[2].r; r++) {
		if (r > corner[0].r) cnt++;
		for (int c = corner[0].c + 1 + cnt; c <= N; c++) {	// �밢 ���� ������ ���������� �и�
			border[r][c] = 2;
		}
	}

	// 3�� ���ű� ǥ��
	cnt = 0;
	for(int r = N; r >= corner[1].r; r--) {
		if (r < corner[3].r) cnt++;
		for (int c = 1; c < corner[3].c - cnt; c++) {
			border[r][c] = 3;
		}
	}

	// 4�� ���ű� ǥ��
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
						corner[0] = { x, y };	// ��
						corner[1] = { x + d1, y - d1 }; // ����
						corner[2] = { x + d2, y + d2 };	// ������
						corner[3] = { x + d1 + d2, y - d1 + d2 };	// �Ʒ�
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