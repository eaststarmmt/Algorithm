#include<iostream>
#define endl "\n"
using namespace std;

int N;
double prob[4];		// 0: 동 1: 서 2: 남 3: 북
bool visited[29][29];

int dr[] = { 0, 0, 1, -1 };		// 동서남북으로 통일함
int dc[] = { 1, -1, 0, 0 };
double result = 0;

void dfs(int r, int c, int cnt, double probability) {
	if (cnt == N) {			// Depth 끝까지 갔는데 처음 간 곳이면 확률 더하기
		result += probability;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (visited[r + dr[i]][c + dc[i]]) continue;	// 이미 방문 했으면 무시

		visited[nr][nc] = true;			//	방문 처리
		if (cnt == 0)
			dfs(nr, nc, cnt + 1, prob[i]);	// 처음 방향 잡을때 곱하면 0에 곱해지므로 그 방향에 대한 확률 그대로 넣기
		else 
			dfs(nr, nc, cnt + 1, probability * prob[i]);	// ex) 동쪽 갔다가 서쪽 갈 확률 = 동쪽 * 서쪽
		visited[nr][nc] = false;		//	나오면 다른 경우 이므로 방문 처리 해제
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 4; i++) {
		double x;
		cin >> x;
		prob[i] = x / 100;
	}

	visited[14][14] = true;
	dfs(14, 14, 0, 0);
	cout.precision(10);			// 소수점 10째짜리까지 표시. 10^-9이 오차 범위 이므로 하나 더 표시해야 안틀림
	cout << result << endl;
}