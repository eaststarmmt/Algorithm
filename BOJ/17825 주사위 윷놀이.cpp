#include <bits/stdc++.h>
using namespace std;

int mal[4], dice[14];
vector<int> graph[50];
int score[104];		// 31이면 충분 하지만 끝점을 100으로 잡았기 때문에 104까지 할당

void add(int here, int there) {
	graph[here].push_back(there);
}

void setGraph() {
	for (int i = 0; i <= 19; i++) {
		graph[i].push_back(i + 1);
	}

	add(5, 21); add(21, 22); add(22, 23); add(23, 24);
	add(24, 25); add(25, 26); add(26, 20);
	add(15, 29); add(29, 30); add(30, 31); add(31, 24);
	add(10, 27); add(27, 28); add(28, 24); add(20, 100);

	score[1] = 2; score[2] = 4; score[3] = 6; score[4] = 8; score[5] = 10;
	score[6] = 12; score[7] = 14; score[8] = 16; score[9] = 18; score[10] = 20;
	score[11] = 22; score[12] = 24; score[13] = 26; score[14] = 28; score[15] = 30;
	score[16] = 32; score[17] = 34; score[18] = 36; score[19] = 38; score[20] = 40;
	score[21] = 13; score[22] = 16; score[23] = 19; score[24] = 25; score[25] = 30;
	score[26] = 35; score[27] = 22; score[28] = 24; score[29] = 28; score[30] = 27; score[31] = 26;
}

int move(int now, int cnt) {
	if (now == 100) return 100;	// 말이 끝까지 간 경우
	if (graph[now].size() >= 2) {	// 시작점에 파란 화살표가 있는 경우
		now = graph[now][1];
		cnt--;
	}
	if (cnt) {
		queue<int> Q;
		Q.push(now);
		int there = now;
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			there = graph[x][0];	// 다음 갈 지점. 시작점이 아니므로 무조건 0번으로 이동
			Q.push(there);
			if (there == 100) break;	// 종점에 갔으면 더 이상 반복문 종료
			if (--cnt == 0) break;	// 주사위 이동 횟수가 종료 되었으면 종료
		}
		return there;
	}
	else {
		return now;
	}
}

bool check(int now, int idx) {
	if (now == 100) return false;	// 종점이면 없는걸로 판단
	for (int i = 0; i < 4; i++) {
		if (i == idx) continue;
		if (mal[i] == now) return true;
	}
	return false;
}

int comb(int cnt) {
	if (cnt == 10) return 0;

	int res = 0;

	for (int i = 0; i < 4; i++) {
		int now = mal[i];	// 조합을 쓰기 위해 원복할 말의 위치 저장
		int move_idx = move(now, dice[cnt]);
		if (check(move_idx, i)) continue;	// 이동한 자리에 말 있으면 불가능
		mal[i] = move_idx;		// 할당 해야 cnt + 1에 이동한 위치가 반영 됨
		res = max(res, score[move_idx] + comb(cnt + 1));
		mal[i] = now;
	}	// end of for i

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}	// end of for dice

	setGraph();
	cout << comb(0) << "\n";

	return 0;
}