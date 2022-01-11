#include<cstdio>
#include<vector>
using namespace std;
int dr[] = { 0, -1, 0, 1 };	// ���� ��ȣ �״��
int dc[] = { 1, 0, -1, 0 };
int map[101][101];
int N, c, r, d, g;
vector<int> save;

int countingSquare() {
	int cnt = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] == 1 && map[i][j + 1] && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)	// ���� �̾��� �ʿ� ���� �������� ������ �Ǵµ�...
				cnt++;
		}
	}
	return cnt;
}

void dragonCurve() {		// �� ���� ����� �ں��� + 1 �ؼ� ���̸� ��
	int size = save.size();
	for (int i = size - 1; i >= 0; i--) {
		int d = (save[i] + 1) % 4;
		r += dr[d];
		c += dc[d];
		map[r][c] = 1;
		save.push_back(d);		// ���� ���� ����� ���� ����
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
		map[r][c] = 1;	// 0���� ����
		save.push_back(d);
		for (int j = 0; j < g; j++) {
			dragonCurve();
		}
	}
	printf("%d\n", countingSquare());
}