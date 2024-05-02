#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define INF 1e9
using namespace std;

int N, M, K, C, res;
int a[24][24], temp[24][24];
int dr[] = { 1, -1, 0, 0, -1, -1, 1, 1 }; //0~3 상하좌우 4~7 대각
int dc[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

int get_cnt(int r, int c) {     // 주변 나무 세는 함수
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;    // 범위 벗어난 경우 무시
		if (a[nr][nc] <= 0) continue;    // 나무 아닌 경우 무시
		cnt++;
	}   // end of for

	return cnt;
}

void growth() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] <= 0) continue;  // 나무가 없는 경우
			int cnt = get_cnt(i, j);    // 주변에 나무 몇그루 있는지 확인
			a[i][j] += cnt;     // 그 수 만큼 성장
		}   // end of for j
	}   // end of for i
}

vector<pair<int, int>> get_blank(int r, int c) {    // 주변 빈칸 위치 저장하는 함수. DRY 할 방법 고민 해봐야 됨
	vector<pair<int, int>> blank;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (a[nr][nc]) continue;     // 빈칸 아니면 무시

		blank.push_back({ nr, nc });
	}   // end of for i

	return blank;
}

void set_tree(int tree, vector<pair<int, int>>& blank) {
	for (pair<int, int> p : blank) {     // 빈 칸에 나무 새로 심기
		int r = p.first;
		int c = p.second;

		temp[r][c] += tree;
	}
}

void set_origin_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] += temp[i][j];  // 번식한 나무를 원래 지도에 더해줌
		}   // end of for j
	}   // end of for i
}

void reproduction() {   // 번식
	// 앞선 나무의 번식으로 인해 카운팅 안되는 문제를 방지하기 위함. 오로지 번식 된 나무만 저장됨
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] <= 0) continue;  // 나무 아니면 무시

			vector<pair<int, int>> blank = get_blank(i, j);     // 나무는 빈 칸에만 번식 가능하기 때문에 빈칸만 가져옴
			if (blank.size() == 0) continue; // 번식할 곳 없으면 무시. divided by 0 나오는 대참사 막기 위함
			int tree = a[i][j] / blank.size();      // 나무 그루 수 / 번식 가능한 칸 수

			set_tree(tree, blank);  // 나무 번식

		}   // end of for j
	}   // end of for i

	// 번식한 나무 원래 지도에 반영
	set_origin_map();

}

void set_herbicide(int r, int c, vector<pair<int, int>>& herbicide) {
	herbicide.push_back({ r, c });
	for (int d = 4; d < 8; d++) {    // 대각 방향
		for (int i = 1; i <= K; i++) {    // K칸 만큼 확산 시키기
			int nr = r + dr[d] * i;
			int nc = c + dc[d] * i;

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (a[nr][nc] < -C) break;     // 벽인 경우 다음 더 진행 안함

			herbicide.push_back({ nr, nc });
			if (a[nr][nc] <= 0) break;    // 나무가 없는 경우 더 이상 진행 안함
		}   // end of for i
	}   // end of for d
}

int get_sum(vector<pair<int, int>> v) {     // 위치가 저장된 벡터 기준으로 죽는 나무 수 카운팅
	int sum = 0;
	for (pair<int, int> p : v) {
		int r = p.first;
		int c = p.second;
		if (a[r][c] <= 0) continue;  // 빈칸이거나 제초제인 경우 무시
		sum += a[r][c];
	}   // end of for
	return sum;
}

void spread(vector<pair<int, int>>& v) {    // 제초제 뿌리기
	for (pair<int, int> p : v) {
		int r = p.first;
		int c = p.second;

		a[r][c] = -C;
	}
}

void herbicide() {  // 제초제 뿌리기
	int r = 0;
	int c = 0;
	int max_sum = 0;   // 죽일 수 있는 나무 수
	vector<pair<int, int>> max_herbicide_list;  // 최댓값 일때 죽일 나무 위치

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] <= 0) continue;   // 나무가 아니면 무시
			vector<pair<int, int>> herbicide_list;  // (i, j)에서 제초제 뿌렸을 때 나무 죽이는 위치
			set_herbicide(i, j, herbicide_list);    // 제초제 뿌릴 수 있는 위치 벡터에 저장
			int sum = get_sum(herbicide_list);  // 현 위치에서 죽는 나무 수 카운팅
			// 최댓값 갱신 된 경우
			if (sum > max_sum) {
				max_sum = sum;
				r = i;
				c = j;
				max_herbicide_list = herbicide_list;
			}
		}  // end of for j
	}   // end of for i
	res += max_sum;
	spread(max_herbicide_list);
}

void reduce_herbicide() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] < 0) a[i][j]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> C;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				a[i][j] = -INF;  // 제초제랑 구분하기 편하게 -10억으로 변경
			}
		}   // end of for j
	}   // end of for i

	while (M--) {
		growth();;
		reproduction();
		reduce_herbicide();
		herbicide();
	}   // end of while

	cout << res << '\n';
}