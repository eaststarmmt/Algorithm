#include<cstdio>
#include<cstring>
#define MAX 100
using namespace std;

int N;
int map[MAX][MAX];
int maxHeight, minHeight = 1e9;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
bool visited[MAX][MAX];

bool dfs(int r, int c, int height) {
	if (visited[r][c] || map[r][c] <= height) return false;	// 물에 잠기거나 방문했으면 나가기
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visited[nr][nc]) {
			dfs(nr, nc, height);
		}
	}
	return true;
}

int main() {
	scanf("%d", &N);
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			maxHeight = map[i][j] > maxHeight ? map[i][j] : maxHeight;
			minHeight = map[i][j] < minHeight ? map[i][j] : minHeight;
		}
	}
	for (int i = minHeight - 1; i <= maxHeight; i++) {
		int cnt = 0;								// 카운팅 초기화
		memset(visited, false, sizeof(visited));	// visited 초기화
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (dfs(r, c, i)) cnt++;	// dfs 과정이 이루어 지면 즉 덩어리가 하나라도 나오면 카운팅
			}
		}
		result = cnt > result ? cnt : result;
	}
	printf("%d\n", result);
}