#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int solution(vector<vector<int>> dots) {
	int answer = 0;
	int x1 = -INF, x2 = INF, y1 = -INF, y2 = INF;

	for (int i = 0; i < dots.size(); i++) {
		int x = dots[i][0];
		int y = dots[i][1];

		x1 = max(x1, x);
		x2 = min(x2, x);
		y1 = max(y1, y);
		y2 = min(y2, y);
	}

	answer = abs(x1 - x2) * abs(y1 - y2);
	return answer;
}