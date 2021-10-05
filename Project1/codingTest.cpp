#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int map[51][51];
int time[51][51];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
vector<pair<int, int>> virus;
vector<pair<int, int>> send;
bool selected[11];
int N, M;
int res = 1e9;
int blank;

void bfs(queue<pair<int, int>> Q) {
	int lastTime = 0;
	int cnt = 0;

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		if (cnt == blank) break;		// ���̷����� ��ĭ��ŭ ���� ������ Ż��

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
				if (map[nr][nc] != 1 && time[nr][nc] == -1) {
					time[nr][nc] = time[r][c] + 1;
					if (map[nr][nc] == 0) {				// ��ĭ�� ���
						lastTime = time[nr][nc];		// bfs Ư���� �������� �ü��� �ð� Ŀ��
						if (lastTime >= res) return;	// ���� �ּҰ����� ũ�� Ż��
						cnt++;							// ��ĭ�� ���� �����Ƿ� ī����

					}
					Q.push({ nr, nc });
				}
			}
		}
	}
	if (cnt == blank)
		res = lastTime < res ? lastTime : res;

}

void comb(int start, int cnt) {
	if (cnt == M) {		// M����ŭ ������
		queue<pair<int, int>> Q;
		memset(time, -1, sizeof(time));	// �ð� ���� -1 �� �ʱ�ȭ
		for (int i = 0; i < virus.size(); i++) {
			if (selected[i]) {
				Q.push({ virus[i].first, virus[i].second });	// ť�� �� �ֱ�
				time[virus[i].first][virus[i].second] = 0;		// ���̷��� �ִ� �ڸ��� 0���� ����
			}
		}
		bfs(Q);
		return;
	}

	for (int i = start; i < virus.size(); i++) {
		if (selected[i]) continue;
		selected[i] = true;
		comb(i + 1, cnt + 1);
		selected[i] = false;

	}

}

int main() {
	//scanf("%d %d", &N, &M);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)					// ���̷��� ��ġ ���� ����
				virus.push_back({ i, j });
			else if (map[i][j] == 0)			// ��ĭ ���� ����
				blank++;
		}
	}
	if (blank == 0) {		// ��ĭ ���� 0�̸� 0 ���
		printf("%d\n", 0);
		return 0;
	}
	comb(0, 0);
	if (res != 1e9)
		cout << res << "\n";
	else
		cout << -1 << "\n";
}