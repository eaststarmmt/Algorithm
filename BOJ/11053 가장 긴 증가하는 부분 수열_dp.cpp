#include<iostream>
#include<algorithm>

using namespace std;

int dp[1004], a[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int res = 0;

    for(int i = 0; i < N; i++) {
        dp[i] = 1;      // 어떤 숫자가 오더라도 증가하는 부분 수열은 항상 1은 보장
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {       // i가 더 크면 j보다 최소 한개는 더 길게 나올 수 있다는 의미
                dp[i] = max(dp[i], dp[j] + 1);  // 지금까지 나온 j 중 최댓값으로 계속 갱신
            }
        }   // end of for j
        res = max(res, dp[i]);      // 증가하는 부분 수열 중 가장 긴 부분 수열 구하기
    }   // end of for i

    cout << res << "\n";
}