#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

long long N, dp[34][34];

long long dynamic(int whole, int half) {
    // 기저 조건
    if(whole == 0 && half == 0) return 1;   // 마지막까지 갔으면 경우의 수 하나 추가하기 위해 1 반환

    // 메모이제이션
    long long &res = dp[whole][half];
    if(res) return res;

    // 한알짜리 약이 남아있으면 약 쪼개는 경우 다 더하기
    if(whole) res += dynamic(whole - 1, half + 1);
    // 반알짜리 약이 남아있으면 반알 꺼내는 경우 다 더하기
    if(half) res += dynamic(whole, half - 1);

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        cin >> N;
        if(N == 0) return 0;

        cout << dynamic(N, 0) << "\n";
    }   // end of while

}