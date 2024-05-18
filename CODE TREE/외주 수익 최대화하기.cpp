#include<iostream>
#include<algorithm>
using namespace std;

int dp[20], T[20], P[20];
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }   // end of for

    for(int i = 0; i < N; i++) {
        dp[i] = max(dp[i], dp[i - 1]);

        if(i + T[i] <= N) {
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]); // 작업이 끝나는 시점을 채우는 개념.
        }
    }   // end of for

    cout << *max_element(dp, dp + N + 1) << "\n";
    return 0;
}