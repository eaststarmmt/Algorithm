#include <string>
using namespace std;
int dr[] = { 1, -1, 0, 0 };   // x y 좌표이므로 상하가 반대임
int dc[] = { 0, 0, -1, 1 };
bool visited[11][11][4];    // 가로 세로 방향
int solution(string dirs) {
	int answer = 0;
	int r = 5;  // -5가 이라고 생각해야 됨
	int c = 5;
	for (int i = 0; i < dirs.size(); i++) {
		int dir;
		// 방향 체크
		if (dirs[i] == 'U') {
			dir = 0;
		}
		else if (dirs[i] == 'D') {
			dir = 1;
		}
		else if (dirs[i] == 'L') {
			dir = 2;
		}
		else {
			dir = 3;
		}
		int nr = r + dr[dir];
		int nc = c + dc[dir];

		if (nr < 0 || nc < 0 || nr >= 11 || nc >= 11) {
			continue;
		}
		if (!visited[nr][nc][dir]) {     // 상하좌우 정확히 따질 필요 없이 그냥 같은 방향으로 왔는지 체크만 하면 됨
			visited[nr][nc][dir] = true;
			if (dir % 2 == 1) dir--;     // 짝수면 + 1 하면 반대방향, 홀수면 -1 하면 반대 방향임
			else dir++;
			visited[r][c][dir] = true;  // 0 -> 1, 1 -> 0 을 같은 경로로 포함 해야됨
			answer++;
		}
		r = nr;
		c = nc;
	}   // end of for
	return answer;
}