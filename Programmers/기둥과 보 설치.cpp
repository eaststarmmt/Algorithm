#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool pole[104][104];
bool bo[104][104];
int N;
struct Info {
	int r, c, type;
	bool flag;
};
vector<Info> build;
bool check(int r, int c) {
	if (r < 0 || c < 0 || r > N || c > N) {
		return false;
	}
	return true;
}

bool cmp(vector<int>& A, vector<int>& B) {
	if (A[0] == B[0]) {
		if (A[1] == B[1]) {
			return A[2] < B[2];
		}
		return A[1] < B[1];
	}
	return A[0] < B[0];
}

bool checkBo(int r, int c) {  // 하나라도 되면 설치
	// 한쪽 끝이라도 기둥에 걸치는지, 혹은 양쪽에 보 있는지
	if (check(r - 1, c) && pole[r - 1][c]) {
		return true;
	}
	if (check(r - 1, c + 1) && (pole[r - 1][c + 1])) {
		return true;
	}
	if (check(r, c - 1) && check(r, c + 1) && bo[r][c - 1] && bo[r][c + 1]) {
		return true;
	}
	return false;
}

bool checkPole(int r, int c) {
	if (r == 0) {
		return true;
	}
	if (check(r, c - 1) && bo[r][c - 1]) {
		return true;
	}
	if (check(r, c) && bo[r][c]) {
		return true;
	}
	if (check(r - 1, c) && pole[r - 1][c]) {
		return true;
	}
	return false;
}

void removeBo(int r, int c) {
	bo[r][c] = false;
	int now = 0;
	for (int i = 0; i < build.size(); i++) {
		if (!build[i].flag) {
			continue;
		}
		int nr = build[i].r;
		int nc = build[i].c;
		int type = build[i].type;

		if (nr == r && nc == c && type == 1) {  // 타입 체크 안하면 보랑 기둥 섞여서 망함
			now = i;
			continue;
		}

		if (type) {
			if (!checkBo(nr, nc)) {
				bo[r][c] = true;
				return;
			}
		}
		else {
			if (!checkPole(nr, nc)) {
				bo[r][c] = true;
				return;
			}
		}

	}	// end of for
	build[now].flag = false;
}

void removePole(int r, int c) {
	pole[r][c] = false;
	int now = 0;
	for (int i = 0; i < build.size(); i++) {
		if (!build[i].flag) {
			continue;
		}
		int nr = build[i].r;
		int nc = build[i].c;
		int type = build[i].type;

		if (nr == r && nc == c && type == 0) {
			now = i;
			continue;
		}

		if (type) {
			if (!checkBo(nr, nc)) {
				pole[r][c] = true;
				return;
			}
		}
		else {
			if (!checkPole(nr, nc)) {
				pole[r][c] = true;
				return;
			}
		}

	}	// end of for
	build[now].flag = false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	N = n;
	for (int i = 0; i < build_frame.size(); i++) {
		int c = build_frame[i][0];
		int r = build_frame[i][1];
		int type = build_frame[i][2];
		int action = build_frame[i][3];

		if (action) {    // 설치
			if (type) {  // 보
				if (checkBo(r, c)) {
					bo[r][c] = true;
					build.push_back({ r, c, type, true });
				}

			}
			else {    // 기둥
				if (checkPole(r, c)) {
					pole[r][c] = true;
					build.push_back({ r, c, type, true });
				}
			}
		}
		else {    // 제거
			if (type) {
				removeBo(r, c);
			}
			else {
				removePole(r, c);
			}
		}
	}   // end of for i

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (bo[i][j]) {
				answer.push_back({ j, i, 1 });
			}
			if (pole[i][j]) {
				answer.push_back({ j, i, 0 });
			}
		}   // end of for j
	}   // end of for i

	sort(answer.begin(), answer.end(), cmp);

	return answer;
}