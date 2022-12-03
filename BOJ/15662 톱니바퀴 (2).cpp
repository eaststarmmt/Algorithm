#include <bits/stdc++.h>
using namespace std;

int T, K, res;
string t[1004];
int start, dir;

int findL(int x) {
	for (int i = x; i >= 1; i--) {
		if (t[i][6] == t[i - 1][2]) return i;	// 같으면 안돌게 됨. 로직은 다음 왼쪽을 확인하는 로직이므로 검증된 현재(i)를 리턴
	}
	return 0;
}

int findR(int x) {
	for (int i = x; i <= T - 2; i++) {
		if (t[i][2] == t[i + 1][6]) return i;
	}
	return T - 1;
}

void rot(int x, int dir) {
	if (dir == 1) {
		rotate(t[x].begin(), t[x].begin() + t[x].size() - 1, t[x].end());
	}
	else {
		rotate(t[x].begin(), t[x].begin() + 1, t[x].end());
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> t[i];
	}	// end of for

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> start >> dir;
		start--;	// 0번 인덱스부터 쓰고 싶어서
		// 회전시킬 범위 지정
		int l = findL(start);
		int r = findR(start);

		// 회전
		int cnt = 0;	// 방향 계속 바꿔야 하므로 카운팅으로 홀짝 체크
		for (int i = start; i >= l; i--) {	// 중심부터 왼쪽 회전
			rot(i, cnt % 2 == 0 ? dir : dir * -1);
			cnt++;
		}	// end of for l

		cnt = 1;	// 1로 하면 위에 코드 그대로 사용 가능. 중심은 했고 반대방향부터 시작이므로

		for (int i = start + 1; i <= r; i++) {	// 중심부터 오른쪽 회전
			rot(i, cnt % 2 == 0 ? dir : dir * -1);
			cnt++;
		}	// end of for r
	}	// end of for K

	for (int i = 0; i < T; i++) {
		if (t[i][0] == '1') res++;
	}

	cout << res << "\n";

	return 0;
}