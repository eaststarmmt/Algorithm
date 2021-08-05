#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int map[102][102];

int dx[] = { -1, 1, 0, 0 };		// vector 형태로 받은게 아니라 4방탐색을 해야됨
int dy[] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
	queue<pair<int, int>> queue;		//pair를 받는 queue 사용
	queue.push({ x, y });
	while (!queue.empty()) {
		int x = queue.front().first;
		int y = queue.front().second;
		queue.pop();							// 이거 까먹으면 무한루프 돔
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[nx][ny] == 1) {				// map이 1이라는건 안가본 곳이고 길이라는 뜻. visited가 굳이 필요 없는 문제
				queue.push({ nx, ny });
				map[nx][ny] = map[x][y] + 1;	// 1부터 시작하고 도착지도 포함을 해서 카운팅 하기 때문에 
			}									// 이전에 있던 곳 + 1 을 하면 경로를 자연스럽게 셀 수 있음
		}
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(1, 1);
	printf("%d\n", map[N][M]);
}