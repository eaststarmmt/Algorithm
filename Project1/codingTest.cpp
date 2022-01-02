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
		int nowDis = 1e9;	// 집 마다 제일 가까운 곳. 즉 최소값 저장할 예정
		for (int j = 0; j < chicken.size(); j++) {
			if (disCard[j]) continue;	// 폐업한 치킨집 통과
			nowDis = min(nowDis, abs(house[i].r - chicken[j].r) + abs(house[i].c - chicken[j].c));
		}
		cityDis += nowDis; // 전체 치킨집과 비교해서 제일 작았던 곳 저장
	}
	ans = cityDis < ans ? cityDis : ans;
}

void comb(int start, int cnt) {
	if (cnt == total - M) { // M 개 만큼 제외 했을때
		calc();	// 치킨 거리 계산
		return;
	}

	for (int i = start; i < total; i++) {
		disCard[i] = true;	// true 가 버리는거
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
			else if (map[i][j] == 2) {	// 치킨집 몇갠지 미리 세두기
				chicken.push_back(Pos{ i, j });
				total++;
			}
		}
	}
	
	comb(0, 0);
	printf("%d\n", ans);
}