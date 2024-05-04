#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
	vector<vector<int>> answer(n, vector<int>(n));
	int r = 0;
	int c = -1;
	int cnt = 1;
	int d = 1;

	while (n) {
		for (int i = 0; i < n; i++) {
			c += d;
			answer[r][c] = cnt++;
		}   // end of for

		n--;

		for (int i = 0; i < n; i++) {
			r += d;
			answer[r][c] = cnt++;
		}   // end of for

		d *= -1;
	}   // end of while
	return answer;
}