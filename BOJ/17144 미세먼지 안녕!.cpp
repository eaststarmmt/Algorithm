#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int up_dr[] = { 0, -1, 0, 1 };	// ���� �̼����� ȸ�� ����
int up_dc[] = { 1, 0, -1, 0 };
int under_dr[] = { 0, 1, 0, -1 };	// �Ʒ��� �̼����� ȸ�� ����
int under_dc[] = { 1, 0, -1, 0 };
vector<pair<int, int>> up_dust, under_dust;	// �̼����� ��ġ�� ����
int m[54][54], temp_dust[54][54];
int R, C, T;

void dust_spread() {
	fill(&temp_dust[0][0], &temp_dust[0][0] + 54 * 54, 0);
	queue<pair<int, int>> Q;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (m[i][j] > 0) {		// �̼� ���� �ִ� ���� ����
				Q.push({ i, j });
			}
		}	// end of for C
	}	// end of for R

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;

		Q.pop();

		int spread = m[r][c] / 5;

		for (int i = 0; i < 4; i++) {
			int nr = r + up_dr[i];
			int nc = c + up_dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C || m[nr][nc] == -1) {	// Ȯ�� �ȵ� �κ��� �� �ʿ� �����Ƿ� ���� ��������
				continue;
			}
			// dust �迭 ���� �ȸ���� ���� ���� �����Ǿ� ���� Ʋ����
			temp_dust[nr][nc] += spread;
			m[r][c] -= spread;		// �� ��ġ���� Ȯ�� �� ��ŭ ����
		}	// end of for i
	}	// end of while Q

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			m[i][j] += temp_dust[i][j];
		}	// end of for C
	}	// end of for R
}

vector<pair<int, int>> setDust(int startR, int startC, int dr[], int dc[]) {
	vector<pair<int, int>> vec;
	int r = startR;
	int c = startC;
	int d = 0;
	while (true) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C) {	// ���� ������� ȸ��
			d++;
			nr = r + dr[d];
			nc = c + dc[d];
		}	// end of if
		if (nr == startR && nc == startC) break;		// �ѹ��� �� �������� break;
		vec.push_back({ nr, nc });
		r = nr;
		c = nc;
	}
	return vec;
}

void turn_dust(vector<pair<int, int>>& dust) {
	// �̹� ������ ����ä�� ��ġ�� ����Ǿ� ����. �׳� ��ĭ�� �б⸸ �ϸ� ��
	for (int i = dust.size() - 1; i > 0; i--) {	// ������ �ε����� ����û����� ���� ��������̹Ƿ� ��������� ��
		m[dust[i].first][dust[i].second] = m[dust[i - 1].first][dust[i - 1].second];
	}	// end of for dust
	m[dust[0].first][dust[0].second] = 0;	// ���� û���� ��ġ�� ���� �κ�
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;

	bool flag = false;	// ����û���� �� �Ʒ� ��ġ �����ϱ� ���� flag
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> m[i][j];
			if (m[i][j] == -1) {	// ����û���� ��ġ���� �̼����� ���⸸ �̸� ���Ϳ� ����
				if (!flag) {
					up_dust = setDust(i, j, up_dr, up_dc);
					flag = true;	// ������ ���� ���� ����
				}
				else {
					under_dust = setDust(i, j, under_dr, under_dc);
				}
			}
		}	// end of for C
	}	// end of for R

	for (int t = 0; t < T; t++) {
		dust_spread();
		turn_dust(up_dust);
		turn_dust(under_dust);
	}	// end of for time

	int res = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			res += m[i][j];
		}
	}

	cout << res + 2 << "\n";		// ���� û���� �� �����̹Ƿ� + 2
	return 0;
}