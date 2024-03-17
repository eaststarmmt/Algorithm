#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[44], vip[44];
int N, M, X;

int go(int x) {
    if(x >= N - 1) return 1;    // 끝까지 다 이동한 경우
    if(vip[x]) return go(x + 1);    // 현재 좌석이 vip이면 다음 좌석 확인

    // 여기서부터는 vip 아닌 경우
    if(dp[x] != -1) return dp[x];

    int &res = dp[x];
    res = 0;
    // 다음자리도 vip가 아니면 자리 바꾸는게 가능. 그리고 그 다음 자리도 vip가 아니라서 다다음과 자리를 바꾸는 경우가 생김
    if(!vip[x + 1]) res = go(x + 1) + go(x + 2);
    else res = go(x + 1);   // 다음자리가 vip면 다다음의 경우를 고려하지 않아도 됨.

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> X;
        vip[--X]++;    // vip 좌석 표시
    }   // end of for

    memset(dp, -1, sizeof(dp));

    cout << go(0);
}