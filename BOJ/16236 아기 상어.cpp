#include<stdio.h>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int map[20][20];
int time[20][20];

int N;
int curR, curC;
int curSize = 2;
int curEat;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int totalTime;

vector < pair<int, pair<int, int>>> eat;

void shark(int r, int c) {
	queue<pair<int, int>> queue;
	queue.push({ r, c });
	eat.clear();						// ������ �ִ� ��� �� ����. �Ÿ� ��� �ٽ� �ؾߵ�
	memset(time, 0, sizeof(time));		// �ɸ��� �ð� ǥ���� �迭 �ʱ�ȭ
	while (!queue.empty()) {
		int r = queue.front().first;
		int c = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (0 <= nr && 0 <= nc && nr < N && nc < N && time[nr][nc] == 0 && curSize >= map[nr][nc]) {	// ���� �ȹ���� ������ ���� ����� ũ�� �۰ų� ���� ��
				queue.push({ nr, nc });
				time[nr][nc] = time[r][c] + 1;							// ���� �ִ� �� + 1�� ���
				if (map[nr][nc] != 0 && curSize > map[nr][nc]) {
					eat.push_back({ time[nr][nc], {nr, nc} });			// �ɸ��� �ð�(�Ÿ�)�� ��ǥ ����
				}
			}
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {		// input
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				curR = i;
				curC = j;
				map[i][j] = 0;
			}
		}
	}

	while (true) {
		shark(curR, curC);
		
		if (eat.empty()) break;		// ������ �ִ°� ������ ����

		sort(eat.begin(), eat.end());	// �ɸ��� �ð� ������ ����
		totalTime += eat[0].first;		// ���� ������ ��ŭ �ð� �߰�
		curEat++;
		if (curEat == curSize) {		// ���� ������ ��ŭ ��Ƹ����� ��� 1 Ŀ��
			curSize++;
			curEat = 0;
		}
		curR = eat[0].second.first;
		curC = eat[0].second.second;
		map[curR][curC] = 0;	// ��Ƹ��� �ڸ� 0���� ����
	}
	printf("%d\n", totalTime);
}