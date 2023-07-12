#include<iostream>
#include<algorithm>
#define INF 1e9
using namespace std;

int dp[10004], N, K;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    // 초기화
    fill(dp, dp + K + 1, INF);
    dp[0] = 0;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;

        for(int j = x; j <= K; j++) {
            dp[j] = min(dp[j], dp[j - x] + 1);  // x 동전 추가해서 K 맞춘 경우랑 지금까지 저장된 K중 작은값 선택
        }   // end of for j
    }   // end of for i

    if(dp[K] == INF) cout << -1 << "\n";
    else cout << dp[K] << "\n";

    return 0;
}