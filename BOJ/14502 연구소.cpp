#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
bool visited[8][8];
int map[8][8];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int result, safe;

class Pos {	// 위치 저장하기 위해 class 생성
public:
	int x, y;

	Pos(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

void bfs(queue<Pos> Q) {
	memset(visited, false, sizeof(visited));	// visited 초기화
	int cnt = 0;
	visited[Q.front().x][Q.front().y] = true;
	while (!Q.empty()) {
		int r = Q.front().x;
		int c = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc] && map[nr][nc] == 0) {
				cnt++;
				Q.push(Pos(nr, nc));
				visited[nr][nc] = true;
				if (safe - cnt - 3 == result) return;	// 기존의 result 이상이면 할 필요 없음
			}
		}
	}
	result = safe - cnt - 3 > result ? safe - cnt - 3 : result;	// 세군데 벽이므로 -3
}

int main() {
	scanf("%d %d", &N, &M);
	vector<Pos> blank;
	queue<Pos> virus;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {		// 빈칸 위치 저장하고 안전지대 개수 세기
				blank.push_back(Pos(i, j));
				safe++;
			}
			else if (map[i][j] == 2) virus.push(Pos(i, j));	// 바이러스 위치 미리 큐에 저장
		}
	}
	
	for (int i = 0; i < blank.size() - 2; i++) {
		map[blank[i].x][blank[i].y] = 1;	// 3중 포문으로 빈칸 위치 벽 설치 -> bfs -> 제거 반복

		for (int j = i + 1; j < blank.size() - 1; j++) {
			map[blank[j].x][blank[j].y] = 1;

			for (int k = j + 1; k < blank.size(); k++) {
				map[blank[k].x][blank[k].y] = 1;

				bfs(virus);

				map[blank[k].x][blank[k].y] = 0;
			}

			map[blank[j].x][blank[j].y] = 0;
		}

		map[blank[i].x][blank[i].y] = 0;
	}
	printf("%d\n", result);
}