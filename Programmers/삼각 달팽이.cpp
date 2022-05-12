#include <string>
#include <vector>
using namespace std;

int map[1001][1001];
int dr[] = { 1, 0, -1 };
int dc[] = { 0, 1, -1 };

vector<int> solution(int n) {
	vector<int> answer;
	int r = 0;
	int c = 1;
	int d = 0;
	int now = 0;
	int width = n;
	// 한 방향으로 채워지는 횟수가 계속 1씩 줄어듬
	while (width > 0) {
		for (int i = 0; i < width; i++) {
			r += dr[d];
			c += dc[d];
			map[r][c] = ++now;
		}   // end of for
		d = (d + 1) % 3;
		width--;
	}   // end of while

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0) break;
			answer.push_back(map[i][j]);
		}   // end of for j
	}   // end of for i
	return answer;
}