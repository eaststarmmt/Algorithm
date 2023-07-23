#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N, K, w, v, dp[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> w >> v;
        for(int j = K; j >= w; j--) {   // 배낭이 견딜 수 있는 무게가 w 이상 있을때만 담기
            dp[j] = max(dp[j], dp[j - w] + v);
        }   // end of for j
    }   // end of for

    cout << dp[K] << "\n";
    return 0;
}