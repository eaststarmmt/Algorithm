#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Info {
	int r, c, rot;
};

struct cmp {
	bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
		if (p1.second == p2.second) return p1.first < p2.first;
		return p1.second > p2.second;
	}
};


struct Cnt {
	int r, c, rot, cnt;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
};

bool cnt_cmp(Cnt c1, Cnt c2) {
	if (c1.cnt == c2.cnt) {
		if (c1.rot == c2.rot) {
			if (c1.c == c2.c) {
				return c1.r < c2.r;
			}
			return c1.c < c2.c;
		}
		return c1.rot < c2.rot;
	}
	return c1.cnt > c2.cnt;
}

int K, M, a[5][5], max_map[5][5], visited[5][5];
queue<int> next_Q;
vector<Cnt> cnt_list;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void print(int m[5][5]) {
	cout << endl;
	cout << "-----------------------------시작-------------------------------------" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "----------------------------끝-----------------------------------------" << endl;
}

int bfs(int start_r, int start_c, int arr[5][5], priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>& pq) {
	queue<pair<int, int>> Q, pos_Q;
	Q.push({ start_r, start_c });
	pos_Q.push({ start_r, start_c });
	visited[start_r][start_c] = 1;

	int cnt = 1;    // 붙어있는 유물 갯수
	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		int val = arr[r][c];
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			int nval = arr[nr][nc];

			if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
			if (visited[nr][nc]) continue;
			if (nval != val) continue;   // 값 다르면 무시

			Q.push({ nr, nc });
			pos_Q.push({ nr, nc });
			visited[nr][nc] = 1;
			cnt++;
		}
	}   // end of while

	if (pos_Q.size() < 3) return 0;  // 세개 이하면 카운팅 안함
	// 3개 이상인 경우만 위치 저장
	while (!pos_Q.empty()) {
		pq.push(pos_Q.front());
		pos_Q.pop();
	}

	return cnt;
}

int calc(int r, int c, int rot_cnt, int copy_map[5][5]) {
	int res = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;    // 같은거 들어간 위치 저장
	memset(visited, 0, sizeof(visited));
	// 해당 맵에서 추출 가능한 유물 개수 찾기
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int cnt = bfs(i, j, copy_map, pq);    // 해당 위치와 인접한 같은 값 개수 찾기
			res += cnt;
		}
	}

	cnt_list.push_back({ r, c, rot_cnt, res, pq });		// 현재 위치에서의 회전에 대한 정보 저장
	return res;
}

void rotate(int r, int c, int rot_cnt, int copy_map[5][5]) {
	int rot_arr[3][3];

	// 복사할 위치 값 저장
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			rot_arr[i][j] = copy_map[r + i][c + j];
		}   // end of for j
	}   // end of for i

	// 회전
	for (int rot = 0; rot < rot_cnt; rot++) {
		int temp[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp[i][j] = rot_arr[3 - j - 1][i];
			}
		}
		memcpy(rot_arr, temp, sizeof(rot_arr));
	}

	// 회전한 값 저장
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			copy_map[r + i][c + j] = rot_arr[i][j];
		}
	}
}

int select_pos() {
	// 우선순위대로 회전
	int max_cnt = 0;
	Info info;
	for (int rot = 1; rot <= 3; rot++) {
		for (int c = 0; c < 3; c++) {
			for (int r = 0; r < 3; r++) {
				int copy_map[5][5];
				memcpy(copy_map, a, sizeof(copy_map));
				rotate(r, c, rot, copy_map);
			//	cout << "r: " << r << " c: " << c << " rot: " << rot << endl;
			//	print(copy_map);
				int cnt = calc(r, c, rot, copy_map);
				max_cnt = max(cnt, max_cnt);
			}	// end of for r
		}	// end of for c
	}	// end of for rot

	return max_cnt;
}

// 가져간 유물 다음 원소로 채우기
void change_map(priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq) {
	while (!pq.empty()) {
		int r = pq.top().first;
		int c = pq.top().second;
		pq.pop();
		
		a[r][c] = next_Q.front();
		next_Q.pop();
	}	// end of while
}


int get_res() {
	int res = 0;
	sort(cnt_list.begin(), cnt_list.end(), cnt_cmp);

	int r = cnt_list[0].r;
	int c = cnt_list[0].c;
	int rot = cnt_list[0].rot;
	int cnt = cnt_list[0].cnt;
	rotate(r, c, rot, a);

	while (cnt) {
		res += cnt;
		change_map(cnt_list[0].pq);
		cnt_list.clear();	// 다시 카운팅 해야 되기 때문에 리셋
		cnt = calc(r, c, rot, a);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> M;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}   // end of for j
	}   // end of for i

	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		next_Q.push(x);
	}   // end of for Q

	while (K--) {
		cnt_list.clear();

		int cnt = select_pos();
		if (!cnt) break;

		int res = get_res();
		if (!res) break;
		
		cout << res << ' ';

	}   // end of while

	cout << '\n';
}

/*

3 14
2 5 7 3 6
4 7 6 2 4
5 3 6 2 7
2 5 3 7 6
4 6 3 2 3
5 1 4 5 3 2 6 3 4 7 5 3 7 5

3 10

 */