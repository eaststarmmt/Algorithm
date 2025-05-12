#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
int R, C, dest_r, dest_c;
int dr[] = { 1, 0, 0, -1 };
int dc[] = { 0, -1, 1, 0 };
string dir = "dlru";    // 사전순 정렬 되게 알파벳 순서대로 방향 확인
string res;

bool check(int x, int y, int r, int c, int k) { // 멘허튼 거리와 k 값의 홀짝이 같아야 됨
	int dis = abs(x - r) + abs(y - c);
	return k >= dis && (dis & 1) == (k & 1);
}

bool abc_check(string s) {
	if (!res.size()) return true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < res[i]) return true;  // 끝까지 안보기 위해 알파벳 작으면 바로 pass
		else if (s[i] > res[i]) return false;
	}
	return true;

}

void comb(int r, int c, int k, string visited) {
	if (visited.size() == k) {
		if (r == dest_r && c == dest_c) {
			res = res.empty() ? visited : min(visited, res);    // 비어있으면 현재 값. 아니면 사전순으로 앞서는 값
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		char nd = dir[i];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
		if (!check(nr, nc, dest_r, dest_c, k - visited.size() - 1)) continue;    // 백트래킹을 위해 도착 가능 여부 계속 체크
		if (!abc_check(visited + nd)) continue;
		comb(nr, nc, k, visited + nd);
	}   // end of for
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
	string answer = "impossible";
	R = n;
	C = m;
	dest_r = --r;
	dest_c = --c;

	if (check(--x, --y, dest_r, dest_c, k)) {
		comb(x, y, k, "");
		answer = res;
	}
	return answer;
}