#include<cstdio>
<<<<<<< HEAD
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int map[100][100];
bool visited[100][100];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int R, C;

void bfs() {
	queue<pair<int, int>> Q;
	vector<int> cheeze;
	int time = 0;
	while (true) {
		Q = queue<pair<int, int>>();	// ť �ʱ�ȭ
		Q.push({ 0, 0 });	// �׻� 0, 0 ���� ����
		for (int i = 0; i < R; i++) {	// visited �ʱ�ȭ
			fill(visited[i], visited[i] + C + 1, false);
		}
		visited[0][0] = true;
		int cnt = 0;
		while (!Q.empty()) {
			int r = Q.front().first;
			int c = Q.front().second;
			Q.pop();
			// �����߿� ���� ġ���� ���. �ۿ��� �����ϹǷ� ������ ��ġ�� push ���ϸ� �����߿� ����� ġ� ����
			if (map[r][c] == 1) {
				map[r][c] = 0;
				cnt++;
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				// ġ���� ��� �̰��� ���� �����Ƿ� �����ϸ� �ϴ� �� �־ ��
				if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]) {
					Q.push({ nr, nc });
					visited[nr][nc] = true;
				}
			}	// end of for ���Ž��
		}	// end of while Q
		if (cnt == 0) break;	// ġ�� ������ ���ѷ��� Ż��
		cheeze.push_back(cnt);
		time++;
	}	// end of while ���ѷ���

	printf("%d\n", time);
	printf("%d\n", cheeze[time - 1]);
}

int main() {

	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
		}
	}
=======
#include<queue>
#include<cstring>
using namespace std;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int map[100][100];
bool visited[100][100];
int cnt;
int H, W;
int preCnt;

void bfs() {
	queue<pair<int, int>> Q;

	Q.push({ 0, 0 });
	visited[0][0] = true;
	
	int time = 0;
	while (cnt > 0) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < H && nc < W) {
				if (map[nr][nc] == 0) {
					
				}
			}
		}
		
	}
}

int main() {
	
	scanf("%d %d", &H, &W);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) cnt++;
		}
	}
	preCnt = cnt;

>>>>>>> 6b412a5d5582b5505f2ff0bc56c9bcc1d7c12fd9
	bfs();
}