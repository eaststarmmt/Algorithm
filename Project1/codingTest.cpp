#include<cstdio>
#include<queue>
#define endl "\n"
using namespace std;

int dr[] = { -1, 0, 1, 0 };		// �� �� �� ��
int dc[] = { 0, 1, 0, -1 };	
int map[101][101];
char rotation[10001];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		map[r][c] = 1;	// 1�� ��� 2�� ��
	}
	int dir;
	scanf("%d", &dir);
	for (int i = 0; i < dir; i++) {
		int x;
		char rot;
		scanf("%d", &x);
		scanf(" %c", &rot);		// ���� �����ϰ� �޾ƾߵ�
		rotation[x] = rot;
	}	// end of input
	int time = 0;
	queue<pair<int, int>> snake;
	snake.push({ 1, 1 });
	int d = 1;
	int r = 1, c = 1;
	while (true) {
		time++;
		// �̵�
		r += dr[d];	// ���� ���� �� ���� ��� r c�� �׳� ������
		c += dc[d];
		if (r < 1 || r > N || c < 1 || c > N || map[r][c] == 2) {	// ���� �ھҰų� ���� ������ return
			printf("%d\n", time);
			return 0;
		}
		snake.push({ r, c });
		if (map[r][c] == 0) {	// ����� ���� ��� ���� �ڸ� �����
			map[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		map[r][c] = 2;

		// ȸ��
		if (rotation[time] == 'L')
			d = (d + 3) % 4;
		else if (rotation[time] == 'D')
			d = (d + 1) % 4;
	}
}
