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

class Pos {	// ��ġ �����ϱ� ���� class ����
public:
	int x, y;

	Pos(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

void bfs(queue<Pos> Q) {
	memset(visited, false, sizeof(visited));	// visited �ʱ�ȭ
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
				if (safe - cnt - 3 == result) return;	// ������ result �̻��̸� �� �ʿ� ����
			}
		}
	}
	result = safe - cnt - 3 > result ? safe - cnt - 3 : result;	// ������ ���̹Ƿ� -3
}

int main() {
	scanf("%d %d", &N, &M);
	vector<Pos> blank;
	queue<Pos> virus;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {		// ��ĭ ��ġ �����ϰ� �������� ���� ����
				blank.push_back(Pos(i, j));
				safe++;
			}
			else if (map[i][j] == 2) virus.push(Pos(i, j));	// ���̷��� ��ġ �̸� ť�� ����
		}
	}
	
	for (int i = 0; i < blank.size() - 2; i++) {
		map[blank[i].x][blank[i].y] = 1;	// 3�� �������� ��ĭ ��ġ �� ��ġ -> bfs -> ���� �ݺ�

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