#include<stdio.h>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

int N, L, R;
int map[50][50];		// 나라별 인구수 저장 배열
int unions[50][50];		// 어느 연합에 들어가있는지 확인하기 위한 배열

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int moveCnt;			// 이동횟수 카운팅

void move(int r, int c, int index) {
	vector<pair<int, int>> unionPair;	// 같은 연합에 들어갈 나라 좌표 저장
	unionPair.push_back({ r, c });
	queue<pair<int, int>> queue;		// bfs에 사용할 큐
	queue.push({ r, c });
	unions[r][c] = index;

	int cnt = 1;						// 연합에 포함된 나라 수
	int sum = map[r][c];				// 연합 총 인구수

	while (queue.size() > 0) {
		int r = queue.front().first;
		int c = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (0 <= nr && 0 <= nc && nr < N && nc < N && unions[nr][nc] == -1) {	// 좌표 범위에 맞고 아직 연합이 있는지 확인 안했으면 실행
				int gap = abs(map[r][c] - map[nr][nc]);		// 차이가 L이상 R이하이면 큐에 집어넣고 좌표 저장하고 합과 카운팅 하기
				if (L <= gap && gap <= R) {
					queue.push({ nr, nc });
					unionPair.push_back({ nr, nc });
					unions[nr][nc] = index;
					cnt++;
					sum += map[nr][nc];
				}
			}
		}
	}
	for (int i = 0; i < unionPair.size(); i++) {	// 저장한 좌표에 있는 나라들 인구 이동
		map[unionPair[i].first][unionPair[i].second] = sum / cnt;
	}
}

int main() {
	scanf("%d %d %d", &N, &L, &R);
	
	for (int i = 0; i < N; i++) {	//input
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	while (true) {
		fill(&unions[0][0], &unions[N - 1][N], -1);	// 연합 번호 확인전에 -1로 초기화

		int index = 0;		// 몇번 조합인지 구분하기 위한 변수

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (unions[i][j] == -1) {
					move(i, j, index);
					index++;	// 연합 하나의 탐색이 끝났으므로 다음 연합 인덱스 값에 1을 추가
				}
			}
		}

		if (index == N * N)		// index가 N*N 이면 연합이 단 한개도 안나왔다는 뜻이므로 탈출
			break;
		moveCnt++;				// 연합이 있었으면 이동횟수 1 증가
	}

	printf("%d\n", moveCnt);
}