#include <bits/stdc++.h>
using namespace std;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
int a[54][54];
bool visited[54][54];
int N, M, res, x, d, k, T;
bool flag;

void setAverage() {
	int sum = 0;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j]) {
				cnt++;
				sum += a[i][j];
			}
		}
	}

	double ave = (double)sum / (double)cnt;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!a[i][j]) continue;		// 지워진 숫자가 1이 되는 참사가 날 수 있음
			if (ave < (double)a[i][j]) a[i][j]--;
			else if (ave > (double)a[i][j]) a[i][j]++;
		}
	}
}

void setZero() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) a[i][j] = 0;
		}
	}
}

void dfs(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = (c + dc[i] + M) % M;	// 회전이 가능하기 때문에

		if (nr < 0 || nr >= N) continue;
		if (!a[nr][nc]) continue;	// 이미 값 지워진 경우 무시
		if (a[r][c] != a[nr][nc]) continue;	// 값 다른 경우 무시
		if (visited[nr][nc]) continue;	// 이미 지우기로 결정한 값이면 무시

		visited[nr][nc] = visited[r][c] = true;	// 지울 값 표시
		flag = true;
		dfs(nr, nc);
	}
}

bool isAdj() {
	flag = false;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!a[i][j]) continue;	// 이미 지워졌으면 무시
			if (visited[i][j]) continue;	// 지울 값으로 표시했으면 무시
			dfs(i, j);
		}	// end of for j
	}	// end of for i

	return flag;
}

void _rotate(int r, int d, int k) {
	vector<int> v;
	for (int c = 0; c < M; c++) {
		v.push_back(a[r][c]);
	}

	if (!d) {		// 반시계
		rotate(v.begin(), v.begin() + M - k, v.end());
	}
	else {	// 시계
		rotate(v.begin(), v.begin() + k, v.end());
	}

	for (int c = 0; c < M; c++) {	// 회전 시킨 값 저장
		a[r][c] = v[c];
	}	// end of for
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}	// end of for i
	}	// end of for j

	for (int i = 0; i < T; i++) {
		cin >> x >> d >> k;
		for (int j = x - 1; j < N; j += x) {	// 행을 0부터 받았기 때문에 x - 1이 반지름이 x인 원판을 의미
			_rotate(j, d, k);
		}	// end of for j
		if (!isAdj()) {
			setAverage();
		}
		else {
			setZero();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			res += a[i][j];
		}
	}
	cout << res << "\n";
	return 0;
}