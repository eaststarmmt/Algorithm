#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
int a[54][54], temp[54][54];
int R, C, T;
vector<pair<int, int>> wind;	// 돌풍의 좌표

int get_dir(int x) {
	if (x < 0) return x + 4;
	else if (x >= 4) return x - 4;
	return x;
}

void difuse() {
	memset(temp, 0, sizeof(temp));	// 먼지 저장할 임시 맵 초기화
	
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (a[r][c] == -1) continue;	// 돌풍 위치면 무시

			int sum = 0;	// 먼지 얼마나 빠져나갔는지 확인하기 위한 변수

			for (int k = 0; k < 4; k++) {	// i, j로부터 사방에 먼지 확산
				int nr = r + dr[k];
				int nc = c + dc[k];

				if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;	// 범위 벗어나면 무시
				if (a[nr][nc] == -1) continue;	// 돌풍이 있는 자리면 무시
				int dust = a[r][c] / 5;
				temp[nr][nc] += dust;	// temp에 확산 된 먼지 더하기
				sum += dust;	// 지금까지 얼마나 빠져나갔는지 저장
			}	// end of for k
			
			temp[r][c] += a[r][c] - sum;	// 원래 있던 맵에서 확산되어 빠져나간 먼지 값 빼고 저장
		}	// end of for j
	}	// end of for i

	// temp는 0으로 초기화 되었기 때문에 돌풍 위치 다시 표시 해줘야 됨
	for (pair<int, int> w : wind) {
		int r = w.first;
		int c = w.second;
		temp[r][c] = -1;
	}	// end of for wind

	memcpy(a, temp, sizeof(temp));	// 원래 지도에 temp 다시 덮어서 확산된 먼지 갱신
}

vector<pair<int, int>> get_dust(int start_r, int start_c, int dir) {
	vector<pair<int, int>> dust;
	// 위치가 계속 이어지므로 밖에다 선언
	int r = start_r;
	int c = start_c;
	int d = 1;	// 오른쪽부터 시작
	
	while (true) {
		int nr = r + dr[d];
		int nc = c + dc[d];

		if (nr < 0 || nr >= R || nc < 0 || nc >= C) {	// 경계면을 넘어가면 회전시켜서 위치 다시 잡아줌
			d = get_dir(d + dir);	// dir로 인해 1씩 증가 혹은 감소하여 시계 혹은 반시계 방향으로 회전함
			nr = r + dr[d];
			nc = c + dc[d];
		}
		// 돌풍 위치로 돌아오면 종료
		if (nr == start_r && nc == start_c) break;
		dust.push_back({ nr, nc });
		r = nr;
		c = nc;
	}	// end of while

	return dust;
}

void rotate_dust(vector<pair<int, int>>& dust, int dir) {
	vector<int> v;	// 추출한 인덱스의 먼지 값을 넣을 벡터
	for (pair<int, int> p : dust) {
		v.push_back(a[p.first][p.second]);
	}	// end of for dust

	// 미세먼지 값 순서를 회전
	rotate(v.begin(), v.end() - 1, v.end());

	// 돌풍에서 나온 공기는 먼지가 없음
	v[0] = 0;

	for (int i = 0; i < dust.size(); i++) {
		int r = dust[i].first;
		int c = dust[i].second;

		a[r][c] = v[i];
	}	// end of for dust
	
}


void clean_dust() {
	int dir = 1;	// 위 아래 방향 다르게 보내기 위한 변수
	for (pair<int, int> w : wind) {	// 돌풍 하나씩 사용
		int r = w.first;
		int c = w.second;

		dir *= -1;	// 위 아래가 시계 반시계라는 것을 이용해서 방향 인덱스를 더할지 뺄지 부호로 결정
		vector<pair<int, int>> dust = get_dust(r, c, dir);	// 회전시킬 먼지 인덱스 받아오기
		rotate_dust(dust, dir);
		
	}	// end of for wind
}

int get_res() {
	int cnt = 2;	// 돌풍이 -1씩 두칸 이므로
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cnt += a[i][j];
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) wind.push_back({ i, j });	// 위에서부터 아래로 내려오기 때문에 0번이 위 1번이 아래가 됨
		}	// end of for j
	}	// end of for i
	
	while (T--) {
		difuse();
		clean_dust();
	}	// end of while

	cout << get_res() << '\n';
	return 0;
}