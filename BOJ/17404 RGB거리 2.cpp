#include<iostream>
#include<algorithm>
#define endl "\n"
#define INF 1e9
using namespace std;

int dp[1001][3];
int house[10001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}
	
	for (int i = 0; i < 3; i++) {	// 1번의 최소값은 자기자신
		dp[1][i] = house[1][i];
	}

	int res = INF;
	
	for (int first = 0; first < 3; first++) {
		
		for (int i = 0; i < 3; i++) {
			if (i == first) 
				dp[1][i] = house[1][i];		// 첫번쨰를 누구를 골랐는지에 따라 연산 세번 함. 
			else 
				dp[1][i] = INF;		// 다른거 골랐을때 섞이는거 대비해서 나머지 INF로 피하기
		}

		for (int i = 2; i <= N; i++) { // 1번집은 위에서 초기화 해둠
			dp[i][0] = house[i][0] + min(dp[i - 1][1], dp[i - 1][2]);	// 0을 골랐을때 그 전에 1과 2를 고른것 중 최소값
			dp[i][1] = house[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = house[i][2] + min(dp[i - 1][0], dp[i - 1][1]);

		}

		for (int i = 0; i < 3; i++) {
			if (i != first)	// 첫번째랑 마지막이 겹치지 않은 경우에 결과 갱신
				res = dp[N][i] < res ? dp[N][i] : res;
			
		}
	}
	cout << res << endl;
}