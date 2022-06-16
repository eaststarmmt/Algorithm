#include <string>
#include <vector>

using namespace std;

void recursive(int n, int from, int by, int to, vector<vector<int>>& answer) {
	if (n == 1) {
		answer.push_back({ from, to });
		return;
	}
	recursive(n - 1, from, to, by, answer);
	recursive(1, from, by, to, answer);
	recursive(n - 1, by, from, to, answer);
}

vector<vector<int>> solution(int n) {
	vector<vector<int>> answer;
	recursive(n, 1, 2, 3, answer);
	return answer;
}