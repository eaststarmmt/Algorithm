#include<iostream>
#include<queue>
#include<string>
using namespace std;

char map[52][52];

int hedR, hedC, waterR, waterC, beaverR, beaverC;
int cnt;

int R, C;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1 , 1 };

queue<pair<int, int>> water, hed;

bool bfs() {
	
	hed.push({ hedR, hedC });
	while(!hed.empty()) {

		cnt++;
		int travel = water.size();				// 큐에 enqueue 작업을 계속 할 것이기 떄문에 사이즈를 미리 잡아야 됨

		for(int i = 0; i < travel; i++) {		// water 큐에 들어있는 만큼 물 사방으로 확장
			int r = water.front().first;
			int c = water.front().second;
			water.pop();
			for (int j = 0; j < 4; j++) {
				int nr = r + dr[j];
				int nc = c + dc[j];
				if (map[nr][nc] == '.' || map[nr][nc] == 'S') {			// 빈 곳이면 물 확장하고 푸쉬
					water.push({ nr, nc });
					map[nr][nc] = '*';
				}
			}
		}


		travel = hed.size();

		for (int i = 0; i < travel; i++) {	// hed에 들어있던 사이즈 만큼 고슴도치가 갈 곳 4방 확장
			int r = hed.front().first;
			int c = hed.front().second;
			hed.pop();
			for (int j = 0; j < 4; j++) {
				int nr = r + dr[j];
				int nc = c + dc[j];

				if (map[nr][nc] == '.') {		// 빈 곳이면 확장
					hed.push({ nr, nc });
					map[nr][nc] = 'S';
				}
				else if (map[nr][nc] == 'D') {	// 도착지에 도착하면 true 반환
					return true;
				}
			}
		}
	
	}
	return false;	// 이동경로가 다 사라질때까지 도착지 못가면 false

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	int R, C;
	cin >> R >> C;
	string input;
	
	for (int i = 1; i <= R; i++) {
		cin >> input;
		for (int j = 1; j <= C; j++) {
			map[i][j] = input[j - 1];
			switch (input[j - 1]) {
			case 'D':
				beaverR = i;
				beaverC = j;
				break;
			case '*':
				water.push({ i, j });	// 물이 여러군데 있을 수도 있어서 미리 받아 놓음
				break;
			case 'S':
				hedR = i;
				hedC = j;
				break;
			}
		}
	}
	if (bfs()) cout << cnt << "\n";
	else cout << "KAKTUS\n";
}