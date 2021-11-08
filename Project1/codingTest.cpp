#include<iostream>
#include<algorithm>
#define endl "\n"
using namespace std;
int dp[1000001];
int seq[1000001];	// 순서를 저장할 배열
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;	// 우선 i - 1 때려박고 시작
		seq[i] = i - 1;			// i 입장에서 이전 과정이 i - 1
		if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) { // i 가 3으로 나누어 지는경우 
			dp[i] = dp[i / 3] + 1;	
			seq[i] = i / 3;	// i / 3을 이전 과정으로 저장
			
		}
		if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {	// 3과 동일
			dp[i] = dp[i / 2] + 1;
			seq[i] = i / 2;
		}
	}
	cout << dp[N] << endl;	// 연산 횟수 출력
	while (N != 0) {		// 1의 이전이 0이므로 0이 될때까지 계속 돌림
		cout << N << ' ';	// N 출력하고
		N = seq[N];			// N 이전 단계로 갱신
	}
}