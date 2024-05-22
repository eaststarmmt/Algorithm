#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int R, C, r, c, K, d;
int a[24][24], dice[6];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { 1, -1, 0, 0 };

void _rotate(vector<int>& idx) {
	vector<int> v;
	// 해당하는 인덱스의 주사위 값들 로테이트를 이용하여 회전
	for (int x : idx) {
		v.push_back(dice[x]);
	}	// end of for

	// 주사위 값 회전
	if (d & 1) rotate(v.begin(), v.end() - 1, v.end());
	else rotate(v.begin(), v.begin() + 1, v.end());

	// 주사위에 값 넣기. 인덱스 순서는 그대로이고 값 순서가 변해서 회전됨
	for (int i = 0; i < idx.size(); i++) {
		dice[idx[i]] = v[i];
	}	// end of for

}

void roll(int nr, int nc) {
	vector<int> idx;
	if (d <= 1) {
		idx = { 4, 1, 5, 3 };
	}
	else {
		idx = { 0, 1, 2, 3 };
	}

    _rotate(idx);

	r = nr;
	c = nc;
}

void change() {
	if (!a[r][c]) {
		a[r][c] = dice[1];
	}
	else {
		dice[1] = a[r][c];
		a[r][c] = 0;
	}
}

void go() {
	int nr = r + dr[d];
	int nc = c + dc[d];
	if (nr < 0 || nr >= R || nc < 0 || nc >= C) return;

	roll(nr, nc);
	change();
	
	cout << dice[3] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> r >> c >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
		}	// end of for j
	}	// end of for i

	for (int i = 0; i < K; i++) {
		cin >> d;
		d--;
		go();
	}

}