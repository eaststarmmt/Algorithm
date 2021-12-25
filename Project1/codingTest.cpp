#include<cstdio>
#include<queue>
#define endl "\n"
using namespace std;

int dr[] = { -1, 0, 1, 0 };		// 상 우 하 좌
int dc[] = { 0, 1, 0, -1 };	
int map[101][101];
char rotation[10001];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		map[r][c] = 1;	// 1이 사과 2가 뱀
	}
	int dir;
	scanf("%d", &dir);
	for (int i = 0; i < dir; i++) {
		int x;
		char rot;
		scanf("%d", &x);
		scanf(" %c", &rot);		// 공백 무시하고 받아야됨
		rotation[x] = rot;
	}	// end of input
	int time = 0;
	queue<pair<int, int>> snake;
	snake.push({ 1, 1 });
	int d = 1;
	int r = 1, c = 1;
	while (true) {
		time++;
		// 이동
		r += dr[d];	// 기존 값을 쓸 일이 없어서 r c를 그냥 갱신함
		c += dc[d];
		if (r < 1 || r > N || c < 1 || c > N || map[r][c] == 2) {	// 벽에 박았거나 몸에 닿으면 return
			printf("%d\n", time);
			return 0;
		}
		snake.push({ r, c });
		if (map[r][c] == 0) {	// 사과가 없는 경우 꼬리 자리 비워줌
			map[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		map[r][c] = 2;

		// 회전
		if (rotation[time] == 'L')
			d = (d + 3) % 4;
		else if (rotation[time] == 'D')
			d = (d + 1) % 4;
	}
}
