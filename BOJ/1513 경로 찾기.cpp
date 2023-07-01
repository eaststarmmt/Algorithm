#include<iostream>
#include<algorithm>
#include<cstring>
#define MOD 1000007
using namespace std;

int N, M, C, a[54][54], dp[54][54][54][54];

int dynamic(int r, int c, int cnt, int prev) {
    // 탈출 조건
    if(r > N || c > M) return 0;    // 지도 벗어난 경우
    if(r == N && c == M) {  // 도착한 경우
        if(a[r][c] == 0 && cnt == 0) return 1;      // 횟수 다 쓰고 마지막이 오락실이 아닌 경우
        if(a[r][c] > prev && cnt == 1) return 1;    // 횟수 한 개 남고 마지막이 갈 수 있는 오락실인 경우
        return 0;   // 나머지는 모두 결과에 포함되면 안되므로 리턴 0
    }

    // 메모이제이션
    int &res = dp[r][c][cnt][prev];
    if(~res) return res;

    res = 0;

    if(a[r][c] == 0) {
        res = (dynamic(r + 1, c, cnt, prev) + dynamic(r, c + 1, cnt, prev)) % MOD;
    } else if(prev < a[r][c]) {
        res = (dynamic(r + 1, c, cnt - 1, a[r][c]) + dynamic(r, c + 1, cnt - 1, a[r][c])) % MOD;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> C;

    // 초기화
    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= C; i++) {
        int r, c;
        cin >> r >> c;
        a[r][c] = i;
    }   // end of for

    for(int i = 0; i <= C; i++) {   // 이동할 횟수
        cout << dynamic(1, 1, i, 0) << ' ';
    }   // end of for

    return 0;
}