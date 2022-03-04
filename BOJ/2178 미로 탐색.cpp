#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int map[102][102];

int dx[] = { -1, 1, 0, 0 };		// vector ���·� ������ �ƴ϶� 4��Ž���� �ؾߵ�
int dy[] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
	queue<pair<int, int>> queue;		//pair�� �޴� queue ���
	queue.push({ x, y });
	while (!queue.empty()) {
		int x = queue.front().first;
		int y = queue.front().second;
		queue.pop();							// �̰� ������� ���ѷ��� ��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[nx][ny] == 1) {				// map�� 1�̶�°� �Ȱ��� ���̰� ���̶�� ��. visited�� ���� �ʿ� ���� ����
				queue.push({ nx, ny });
				map[nx][ny] = map[x][y] + 1;	// 1���� �����ϰ� �������� ������ �ؼ� ī���� �ϱ� ������ 
			}									// ������ �ִ� �� + 1 �� �ϸ� ��θ� �ڿ������� �� �� ����
		}
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(1, 1);
	printf("%d\n", map[N][M]);
}