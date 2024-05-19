#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Atom {
	int r, c, m, s, d;
};

int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K, r, c, m, s, d;
vector<Atom> atomies;   // 원자들 관리할 벡터
vector<Atom> a[54][54]; // 더하고 나누기 위함

// 지도 범위 넘어가지 않게 표시
int map_check(int x) {
	if (x % N == 0) return N;
	else if (x > N) return x % N;
	else if (x < 1) return N + (x % N);
	return x;
}

void move() {
	// 맵에 원자들 이동하는거랑 안겹치게 다 지우기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			a[i][j].clear();
		}   // end of for j
	}   // end of for i

	for (int i = 0; i < atomies.size(); i++) {
		// 이동하는 위치 잡기
		int nr = map_check(atomies[i].r + dr[atomies[i].d] * atomies[i].s);
		int nc = map_check(atomies[i].c + dc[atomies[i].d] * atomies[i].s);
		// 해당 위치에 원자 놓기
		a[nr][nc].push_back({ nr, nc, atomies[i].m, atomies[i].s, atomies[i].d });
		// 바뀐 위치 변경
		atomies[i].r = nr;
		atomies[i].c = nc;
	}   // end of for Atom
}

void synthesis() {	// 합성
	vector<Atom> temp;	// 합성하고 분해하면서 새로 생긴 원자들 임시 저장할 벡터

	// 같은 위치에 있는 원자들 합성
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// 한 개 밖에 없는 경우 temp에 담고 합성 분해 로직은 시행햐지 않음
			if (a[i][j].size() == 1) temp.push_back(a[i][j][0]);
			if (a[i][j].size() <= 1) continue;	// 한 개 이하인 경우 합성 로직 수행하지 않기 위해 continue;
			int m_sum = 0;	// 질량 합
			int s_sum = 0;	// 속도 합
			bool is_ewsn = false;	// 상하좌우 있었는지 여부
			bool is_diag = false;	// 대각선 있었는지 여부

			for (Atom atom : a[i][j]) {
				m_sum += atom.m;
				s_sum += atom.s;
				// 홀수면 대각 짝수면 상하좌우
				if (atom.d & 1) is_diag = true;
				else is_ewsn = true;
			}	// end of for atom

			int k = 0;	// 대각이면 1 아니면 0을 둬서 홀 짝을 더 할 변수
			if (is_diag && is_ewsn) k = 1;	// 대각을 둬아 하는 상황이면 1로 변경

			int cnt = a[i][j].size();	// 속력 구하기 위해 원래 몇개 있었는지 저장
			a[i][j].clear();	// 네개로 나눈 원소 들어가야 되기 때문에 비워주기
			if (m_sum / 5 == 0) continue;	// 질량이 0이면 소멸

			// 원소 네개로 나누기
			for (int x = 0; x < 4; x++) {
				a[i][j].push_back({ i, j, m_sum / 5, s_sum / cnt, 2 * x + k });		// k 값이 1이면 1, 3, 5, 7. 0이면 0, 2, 4, 6이 들어감
				temp.push_back({ i, j, m_sum / 5, s_sum / cnt, 2 * x + k });
			}	// end of for divide

		}	// end of for j
	}	// end of for i

	atomies = temp;		// 원자 정보 업데이트
}

int get_res() {
	int res = 0;
	for (Atom atom : atomies) {
		res += atom.m;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		Atom atom = { r, c, m, s, d };
		atomies.push_back(atom);
	}   // end of for

	while (K--) {
		move();
		synthesis();
	}   // end of while

	cout << get_res() << '\n';
	return 0;
}