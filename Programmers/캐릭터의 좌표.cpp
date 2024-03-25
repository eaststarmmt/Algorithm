#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> d = {
	{"up", 1},
	{"down", 0},
	{"left", 2},
	{"right", 3},
};

int dc[] = { -1, 1, 0, 0 };
int dr[] = { 0, 0, -1, 1 };
int C, R;

vector<int> solution(vector<string> keyinput, vector<int> board) {
	vector<int> answer = { 0, 0 };
	R = board[0] / 2;
	C = board[1] / 2;

	for (string s : keyinput) {
		int dir = d[s];
		int nr = answer[0] + dr[dir];
		int nc = answer[1] + dc[dir];

		if (nr < -R || nr > R || nc < -C || nc > C) continue;
		answer = { nr, nc };
	}
	return answer;
}