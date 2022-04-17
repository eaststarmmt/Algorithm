#include <string>
#include <vector>
#include <cstring>
using namespace std;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
bool visited[5][5];
bool flag;      // 거리두기 지켜지고 있는지 확인하기 위한 flag 변수. false면 지켜짐, true면 안지켜짐
bool checked(int r, int c) {    // map 벗어나는지 체크
	if (r < 0 || r >= 5 || c < 0 || c >= 5 || visited[r][c])
		return false;
	return true;
}

void dfs(vector<string>& places, int r, int c, int dis) {
	if (dis == 2) return;
	if (flag) return;
	visited[r][c] = true;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (checked(nr, nc)) {
			if (places[nr][nc] == 'O') {
				dfs(places, nr, nc, dis + 1);
			}
			else if (places[nr][nc] == 'P') {
				flag = true;
				return;
			}
		}
	}
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (int room = 0; room < places.size(); room++) {   // 강의실
		flag = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (places[room][i][j] == 'P') {    // 사람이 앉은 자리부터 맨해튼 거리 확인
					dfs(places[room], i, j, 0);
					if (flag) break;     // 하나라도 안맞으면 탈출
				}
			}   // end of for j
			if (flag) {  // 이미 하나라도 어긋나서 0 넣고 다음 강의실 확인
				answer.push_back(0);
				break;
			}
			else if (!flag && i == 4) { // 마지막 행까지 다 확인 했는데 flag가 false이면 다 지켜진 경우라 판단
				answer.push_back(1);
			}
		}   // end of for i
	}   // end of for room

	return answer;
}