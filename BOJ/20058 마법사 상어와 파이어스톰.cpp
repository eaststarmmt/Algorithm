#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, Q, output_sum, output_max;
int a[70][70], temp[70][70], temp2[70][70], visited[70][70];
vector<int> level_list;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void print(int arr[70][70]) {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void set_map(int r, int c, int len) {
	memset(temp, 0, sizeof(temp));
	memset(temp, 0, sizeof(temp2));

	// temp에 회전 시킬 부분 복사
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			temp[i][j] = a[i + r][j + c];
		}   // end of for j
	}   // end of for i

	// temp2에 회전시켜서 저장
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			temp2[i][j] = temp[len - j - 1][i];
		}
	}

	// 회전 시킨 부분 저장
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			a[i + r][j + c] = temp2[i][j];
		}
	}
}

void rotate(int r, int c, int len, int level) {     // 시작지점(r, c), 시작지점부터 길이, 목표 길이
	if (len == level) {
		set_map(r, c, len);
		return;
	}

	int next_len = len >> 1;
	rotate(r, c, next_len, level);
	rotate(r + next_len, c, next_len, level);
	rotate(r, c + next_len, next_len, level);
	rotate(r + next_len, c + next_len, next_len, level);
}

void melt() {
	memcpy(temp, a, sizeof(a));     // 동시성을 지키기 위해 작업이 끝나기 전까지 원본이 필요함. 비교는 무조건 temp에서만

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!temp[i][j]) continue;   // 얼음 아니면 무시
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nr = i + dr[dir];
				int nc = j + dc[dir];
				if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
				if (!temp[nr][nc]) continue;
				cnt++;
			}   // end of for dir
			if (cnt >= 3) continue;
			a[i][j]--;
		}   // end of for j
	}   // end of for i
}

int dfs(int r, int c) {
	int res = 1;
	visited[r][c] = 1;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (!a[nr][nc]) continue;
		if (visited[nr][nc]) continue;

		res += dfs(nr, nc);
	}   // end of for

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	N = (1 << N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}   // end of for j
	}   // end of for i

	for (int i = 0; i < Q; i++) {
		int x;
		cin >> x;
		level_list.push_back(x);
	}   // end of for

	for (int level : level_list) {
		if (level) rotate(0, 0, N, (1 << level));
		melt();
	}   // end of for

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][i]) continue;
			if (!a[i][j]) continue;
			output_max = max(output_max, dfs(i, j));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			output_sum += a[i][j];
		}
	}

	cout << output_sum << '\n' << output_max << '\n';
	return 0;
}
