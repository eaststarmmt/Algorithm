#include<iostream>
#define INF 1e9
using namespace std;

int dp[10004], N, K, x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    // 초기화
    dp[0] = 1;  // 0을 만드는 경우의 수를 1로 잡아서 추가하는 방식

    for(int i = 0; i < N; i++) {
        cin >> x;
        for(int j = x; j <= K; j++) {
            dp[j] += dp[j - x];     // x 동전을 하나 추가해서 만든 것이기 때문에 경우의 수의 경우에는 같은 값이 추가됨
        }   // end of for j
    }   // end of for i

    cout << dp[K] << "\n";
    return 0;
}