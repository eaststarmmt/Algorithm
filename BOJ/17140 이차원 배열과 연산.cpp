#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Info {
	int cnt, num;
};

int map[101][101];
int R, C, K;
int Row, Col;	// 행과 열 개수 카운팅 할 변수
int counting[101];

bool cmp(Info a, Info b) {
	if (a.cnt == b.cnt)
		return a.num < b.num;
	return a.cnt < b.cnt;
}

void RCalc() {
	int tempCol = Col;
	Col = 0;	// 최대 column 개수 갱신할 변수
	for (int r = 1; r <= Row; r++) {
		vector<Info> info;	// 줄 바뀔때마다 새로 해야 됨
		fill(counting, counting + 101, 0);	// 0으로 초기화
		for (int c = 1; c <= tempCol; c++) {
			counting[map[r][c]]++;	// 숫자 카운팅
		}	// end of counting
		for (int num = 1; num <= 100; num++) {
			if(counting[num] != 0)
				info.push_back({ counting[num], num });
		}	// end of push
		sort(info.begin(), info.end(), cmp);	// 등장 횟수 숫자 오름차순 정렬

		for(int c = 1; c <= tempCol; c++) {		// 기존에 col 길이가 더 길어서 이전 값이 남는걸 방지
			map[r][c] = 0;
		}	

		int c = 0;
		for (int i = 0; i < info.size(); i++) {	// 맵에 새로운 값 채우기
			map[r][++c] = info[i].num;
			map[r][++c] = info[i].cnt;
		}
		Col = c > Col ? c : Col;	// 최대값 구하기
	}
}

void CCalc() {
	int tempRow = Row;
	Row = 0;
	for (int c = 1; c <= Col; c++) {
		vector<Info> info;
		fill(counting, counting + 101, 0);	// 0으로 초기화
		for (int r = 1; r <= tempRow; r++) {
			counting[map[r][c]]++;	// 숫자 카운팅
		}	// end of counting
		for (int num = 1; num <= 100; num++) {
			if (counting[num] != 0)
				info.push_back({ counting[num], num });
		}	// end of push
		sort(info.begin(), info.end(), cmp);	// 등장 횟수 숫자 오름차순 정렬

		for (int r = 1; r <= tempRow; r++) {		// 기존에 row 길이가 더 길어서 이전 값이 남는걸 방지
			map[r][c] = 0;
		}

		int r = 0;
		for (int i = 0; i < info.size(); i++) {	// 맵에 새로운 값 채우기
			map[++r][c] = info[i].num;
			map[++r][c] = info[i].cnt;
		}
		Row = r > Row ? r : Row;	// 최대값 구하기
	}
}

int main() {
	scanf("%d %d %d", &R, &C, &K);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &map[i][j]);
		}
	}	// end of map
	Row = Col = 3;
	if (map[R][C] == K) {	// 처음부터 조건 만족했을 경우 0 출력 후 종료
		printf("%d\n", 0);
		return 0;
	}
	for (int i = 1; i <= 100; i++) {
		if (Row >= Col) {
			RCalc();
		}
		else {
			CCalc();
		}
		if (map[R][C] == K) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", -1);
}