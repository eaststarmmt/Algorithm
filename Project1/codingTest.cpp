#include<iostream>
#include<string>
#define MAXR 10000
#define MAXC 500
using namespace std;

int R, C;
char map[MAXR][MAXC];
bool visited[MAXR][MAXC];
int dr[] = { -1, 0, 1 };		// 위쪽 대각, 직진, 아래 대각 순으로 함
int dc[] = { 1, 1, 1 };			// 위에서부터 확인하기 때문에 아래로 도착하는것 보다는 위로 도착해야 하나라도 더 확보 가능하다고 판단

bool dfs(int r, int c) {
	visited[r][c] = true;

	if (c == C - 1) return true;	// 도착시 true 리턴

	for (int i = 0; i < 3; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= R || nc >= C || visited[nr][nc] ) continue;	// 벗어나거나 이미 지나간 경우 무시
		if (map[nr][nc] == '.') {
			if (dfs(nr, nc)) return true;			// 여기서 true를 안가져가면 실제 true가 반환 안되기 때문에 true가 한번 뜨면 계속 가져가기
		}											// false는 가져가면 다른 경로 확인도 안하고 false 가 되므로 무시
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) {
			map[i][j] = input[j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < R; i++) {				// 한 열씩 확인해보기
		if (dfs(i, 0)) {
			cnt++;
		}
	}
	cout << cnt << "\n";
}