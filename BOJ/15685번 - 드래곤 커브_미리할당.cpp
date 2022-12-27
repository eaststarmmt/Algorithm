#include <bits/stdc++.h>
using namespace std;

int dr[] = { 0, -1, 0, 1 };
int dc[] = { 1, 0, -1, 0 };
int N, nr, nc, d, g, c, r;
int _map[104][104];
vector<int> dragon[4][11];	// 방향, 세대

void dragon_curve() {	// 일단 드래곤 커브 모든 경우 다 저장
	for (int i = 0; i < 4; i++) {	// 시작방향 네개 이므로
		dragon[i][0].push_back(i);	// 0세대 1세대는 미리 저장
		dragon[i][1].push_back((i + 1) % 4);

		for (int j = 2; j <= 10; j++) {	// 2세대부터 10세대 까지
			int size = dragon[i][j - 1].size();

			for (int k = size - 1; k >= 0; k--) {
				dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
			}	// end of for 전 세대 역순

			for (int k = 0; k < size; k++) {
				dragon[i][j].push_back(dragon[i][j - 1][k]);
			}	// end of for 전 세대 그대로 

		}	// end of for 세대
	}	// end of for 시작방향
}

void mark() {
	nr = r;
	nc = c;
	for (int i = 0; i <= g; i++) {	// 0세대부터 입력받은 세대까지
		_map[nr][nc] = 1;
		for (int x : dragon[d][i]) {	// 세대별로 이동할 방향 저장되어 있음
			nr += dr[x];
			nc += dc[x];
			_map[nr][nc] = 1;
		}	// 세대 별로 방향 이동해서 맵에 표시
	}	// end of for 세대
}

int getRes() {
	int res = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (_map[i][j] && _map[i + 1][j] && _map[i][j + 1] && _map[i + 1][j + 1])
				res++;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	dragon_curve();

	for (int i = 0; i < N; i++) {
		cin >> c >> r >> d >> g;
		mark();
	}

	cout << getRes() << "\n";

	return 0;
}