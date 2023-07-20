#include<iostream>
using namespace std;

int a[2004], dp[2004][2004], N, M, S, E;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }   // end of for

    for(int i = 1; i <= N; i++) {
        dp[i][i] = 1;   // 길이가 1이면 팰린드롬임
    }

    cin >> M;

    for(int i = 1; i < N; i++) {
        if(a[i] == a[i + 1]) {  // 숫자 두개가 연속으로 나오면 그것도 팰린드롬임
            dp[i][i + 1] = 1;
        }
    }

    for(int size = 2; size < N; size++) {
        for(int i = 1; i < N; i++) {
            if(a[i] == a[i + size] && dp[i + 1][i + size - 1]) {    // 팰린드롬을 같은 숫자가 감싸면 그것도 팰린드롬
                dp[i][i + size] = 1;
            }
        }   // end of for i
    }   // end of for size

    while(M--) {
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }
}