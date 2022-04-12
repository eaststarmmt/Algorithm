#include<stdio.h>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int map[20][20];
int time[20][20];

int N;
int curR, curC;
int curSize = 2;
int curEat;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int totalTime;

vector < pair<int, pair<int, int>>> eat;

void shark(int r, int c) {
	queue<pair<int, int>> queue;
	queue.push({ r, c });
	eat.clear();						// 먹을수 있는 목록 다 지움. 거리 계산 다시 해야됨
	memset(time, 0, sizeof(time));		// 걸리는 시간 표시할 배열 초기화
	while (!queue.empty()) {
		int r = queue.front().first;
		int c = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (0 <= nr && 0 <= nc && nr < N && nc < N && time[nr][nc] == 0 && curSize >= map[nr][nc]) {	// 지도 안벗어나고 가본적 없고 물고기 크기 작거나 같을 때
				queue.push({ nr, nc });
				time[nr][nc] = time[r][c] + 1;							// 현재 있는 곳 + 1로 계산
				if (map[nr][nc] != 0 && curSize > map[nr][nc]) {
					eat.push_back({ time[nr][nc], {nr, nc} });			// 걸리는 시간(거리)와 좌표 저장
				}
			}
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {		// input
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				curR = i;
				curC = j;
				map[i][j] = 0;
			}
		}
	}

	while (true) {
		shark(curR, curC);
		
		if (eat.empty()) break;		// 먹을수 있는게 없으면 종료

		sort(eat.begin(), eat.end());	// 걸리는 시간 순으로 정렬
		totalTime += eat[0].first;		// 가장 가까운것 만큼 시간 추가
		curEat++;
		if (curEat == curSize) {		// 본인 사이즈 만큼 잡아먹으면 상어 1 커짐
			curSize++;
			curEat = 0;
		}
		curR = eat[0].second.first;
		curC = eat[0].second.second;
		map[curR][curC] = 0;	// 잡아먹은 자리 0으로 갱신
	}
	printf("%d\n", totalTime);
}