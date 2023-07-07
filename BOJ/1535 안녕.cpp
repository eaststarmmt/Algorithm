#include<iostream>
#include<algorithm>
using namespace std;

int N, dp[104], L[24], J[24];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> J[i];
    }   // end of for L

    for(int i = 0; i < N; i++) {
        cin >> L[i];
    }   // end of for J

    for(int i = 0; i < N; i++) {
        for(int j = 100; j > J[i]; j--) {      // 체력이 J[i] 이하로 남으면 의미 없음
            dp[j] = max(dp[j], dp[j - J[i]] + L[i]);    // i번쨰를 더해서 나온 값과 기존의 값 중 최대값을 선택
        }
    }

    cout << dp[100] << "\n";
}