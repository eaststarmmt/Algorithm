#include <vector>
#include <cstring>
using namespace std;

int MOD = 20170805;
int rdp[504][504], ddp[504][504];   // 오른쪽 이동 저장하는 dp와 왼쪽 이동 저장하는 dp

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	memset(rdp, 0, sizeof(rdp));
	memset(ddp, 0, sizeof(ddp));
	int answer = 0;
	rdp[1][1] = ddp[1][1] = 1;  // 테두리 확인 안하기 위해 1부터 시작

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (city_map[i - 1][j - 1] == 0) {
				rdp[i][j] = (rdp[i][j] + rdp[i][j - 1] + ddp[i - 1][j]) % MOD;  // 시작점 넣기 위해 자기 자신도 더해야 됨
				ddp[i][j] = (ddp[i][j] + rdp[i][j - 1] + ddp[i - 1][j]) % MOD;
			}
			else if (city_map[i - 1][j - 1] == 2) {
				rdp[i][j] = rdp[i][j - 1] % MOD;  // 왼쪽에서 오는 경우
				ddp[i][j] = ddp[i - 1][j] % MOD;   // 위쪽에서 오는 경우
			}
		}   // end of for
	}   // end of for

	answer = (rdp[m][n - 1] + ddp[m - 1][n]) % MOD;
	return answer;
}