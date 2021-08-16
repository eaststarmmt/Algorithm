#include<stdio.h>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

int N, L, R;
int map[50][50];		// ���� �α��� ���� �迭
int unions[50][50];		// ��� ���տ� ���ִ��� Ȯ���ϱ� ���� �迭

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int moveCnt;			// �̵�Ƚ�� ī����

void move(int r, int c, int index) {
	vector<pair<int, int>> unionPair;	// ���� ���տ� �� ���� ��ǥ ����
	unionPair.push_back({ r, c });
	queue<pair<int, int>> queue;		// bfs�� ����� ť
	queue.push({ r, c });
	unions[r][c] = index;

	int cnt = 1;						// ���տ� ���Ե� ���� ��
	int sum = map[r][c];				// ���� �� �α���

	while (queue.size() > 0) {
		int r = queue.front().first;
		int c = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (0 <= nr && 0 <= nc && nr < N && nc < N && unions[nr][nc] == -1) {	// ��ǥ ������ �°� ���� ������ �ִ��� Ȯ�� �������� ����
				int gap = abs(map[r][c] - map[nr][nc]);		// ���̰� L�̻� R�����̸� ť�� ����ְ� ��ǥ �����ϰ� �հ� ī���� �ϱ�
				if (L <= gap && gap <= R) {
					queue.push({ nr, nc });
					unionPair.push_back({ nr, nc });
					unions[nr][nc] = index;
					cnt++;
					sum += map[nr][nc];
				}
			}
		}
	}
	for (int i = 0; i < unionPair.size(); i++) {	// ������ ��ǥ�� �ִ� ����� �α� �̵�
		map[unionPair[i].first][unionPair[i].second] = sum / cnt;
	}
}

int main() {
	scanf("%d %d %d", &N, &L, &R);
	
	for (int i = 0; i < N; i++) {	//input
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	while (true) {
		fill(&unions[0][0], &unions[N - 1][N], -1);	// ���� ��ȣ Ȯ������ -1�� �ʱ�ȭ

		int index = 0;		// ��� �������� �����ϱ� ���� ����

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (unions[i][j] == -1) {
					move(i, j, index);
					index++;	// ���� �ϳ��� Ž���� �������Ƿ� ���� ���� �ε��� ���� 1�� �߰�
				}
			}
		}

		if (index == N * N)		// index�� N*N �̸� ������ �� �Ѱ��� �ȳ��Դٴ� ���̹Ƿ� Ż��
			break;
		moveCnt++;				// ������ �־����� �̵�Ƚ�� 1 ����
	}

	printf("%d\n", moveCnt);
}