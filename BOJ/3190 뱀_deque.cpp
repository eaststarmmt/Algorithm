#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N, L, K;
int _map[104][104];
int visited[104][104];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
vector<pair<int, int>> rot;
deque<pair<int, int>> snake;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> K;

	for (int i = 0; i < K; i++) {	// 사과 위치 저장
		int r, c;
		cin >> r >> c;
		_map[--r][--c] = 1;		// 시작점 0, 0으로 잡기 위함
	}

	cin >> L;

	for (int i = 0; i < L; i++) {	// 회전 시점 저장
		int x;
		char c;
		cin >> x >> c;
		if (c == 'L') {
			rot.push_back({ x, 3 });	// 한방향으로 더하고 %4 하기 위함
		}
		else {
			rot.push_back({ x, 1 });
		}
	}	// end of for L

	int time = 0;
	int d = 1;	// 시작 방향은 오른쪽
	int idx = 0; // 회전 시간 체크용 인덱스
	snake.push_back({ 0, 0 });
	while (true) {
		time++;
		int r = snake.front().first;	// 뱀 머리 위치
		int c = snake.front().second;
		int nr = r + dr[d];
		int nc = c + dc[d];

		// 종료 조건 체크
		if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) {		// 벽 or 몸통에 닿는 경우
			break;
		}
		// 머리 늘리기
		snake.push_front({ nr, nc });
		visited[nr][nc] = 1;
		// 사과 여부 체크
		if (_map[nr][nc]) {	// 사과 있는 경우 꼬리 유지하고 사과만 제거
			_map[nr][nc] = 0;
		}
		else {	// 사과 없는 경우 꼬리 제거
			visited[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		// 특정 시간 지난 후 회전
		if (time == rot[idx].first) {
			d = (d + rot[idx].second) % 4;
			idx++;
		}

	}	// end of while

	cout << time << endl;

	return 0;
}