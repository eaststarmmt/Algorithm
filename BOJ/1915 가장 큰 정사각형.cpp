#include<stdio.h>
#include<algorithm>
using namespace std;

int rect[1000][1000];
int dp[1000][1000];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &rect[i][j]);
		}
	}
	int res = rect[0][0];
	if (n > 1)
		res = res > rect[0][1] ? res : rect[0][1];

	if (m > 1)
		res = res > rect[1][0] ? res : rect[1][0];

	if (n == 1 || m == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res = res > rect[i][j] ? res : rect[i][j];
			}
		}
	}
	//int res = max(max(rect[0][0], rect[0][1]), rect[1][0]);

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (rect[i][j] != 0) {			// 왼쪽, 위, 왼쪽위 대각선이 있으면 하나 늘려줘야됨
				rect[i][j] = min(min(rect[i - 1][j - 1], rect[i][j - 1]), rect[i - 1][j]) + 1;
				res = res > rect[i][j] ? res : rect[i][j];		// 가장 큰 값 계속 저장해두기
			}
		}
	}
	printf("%d", res * res);
}