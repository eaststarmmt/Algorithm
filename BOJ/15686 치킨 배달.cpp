#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct Pos {
	int r, c;
};

vector<Pos> house, chicken;
bool disCard[13];
int map[50][50];
int N, M, total;
int ans = 1e9;

void calc() {
	int cityDis = 0;
	for (int i = 0; i < house.size(); i++) {
		int nowDis = 1e9;	// �� ���� ���� ����� ��. �� �ּҰ� ������ ����
		for (int j = 0; j < chicken.size(); j++) {
			if (disCard[j]) continue;	// ����� ġŲ�� ���
			nowDis = min(nowDis, abs(house[i].r - chicken[j].r) + abs(house[i].c - chicken[j].c));
		}
		cityDis += nowDis; // ��ü ġŲ���� ���ؼ� ���� �۾Ҵ� �� ����
	}
	ans = cityDis < ans ? cityDis : ans;
}

void comb(int start, int cnt) {
	if (cnt == total - M) { // M �� ��ŭ ���� ������
		calc();	// ġŲ �Ÿ� ���
		return;
	}

	for (int i = start; i < total; i++) {
		disCard[i] = true;	// true �� �����°�
		comb(i + 1, cnt + 1);
		disCard[i] = false;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				house.push_back(Pos{ i, j });
			}
			else if (map[i][j] == 2) {	// ġŲ�� ��� �̸� ���α�
				chicken.push_back(Pos{ i, j });
				total++;
			}
		}
	}
	
	comb(0, 0);
	printf("%d\n", ans);
}