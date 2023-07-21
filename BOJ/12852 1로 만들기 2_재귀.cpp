#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, dp[1000004];

void dynamic(int x) {
    if(x == 0) return;  // 탈출 조건
    cout << x << ' ';
    if(x % 3 == 0 && dp[x / 3] + 1 == dp[x]) dynamic(x / 3);    // 3으로 나눈 경우가 현재 과정과 횟수가 같은 경우
    else if(x % 2 == 0 && dp[x / 2] + 1 == dp[x]) dynamic(x / 2);   // 2로 나눈 경우가 현재 과정과 횟수가 같은 경우
    else dynamic(x - 1);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    fill(dp, dp + N + 1, INF);
    dp[1] = 0;

    for(int i = 2; i <= N; i++) {
        if(i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
        if(i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
        dp[i] = min(dp[i - 1] + 1, dp[i]);
    }   // end of for

    cout << dp[N] << "\n";
    dynamic(N);
}