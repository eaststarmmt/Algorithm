#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, K;
int wt[104], wm[104], bt[104], bm[104]; // 도보 시간, 도보 금액, 자전거 시간, 자전거 금액
int dp[104][100004];    // 구간, 걸린 시간

int go(int here, int time) {
    if(here == N) {     // 끝까지 간 경우
        return 0;
    }

    int &res = dp[here][time];
    if(res) return res;     // 이미 갱신된 적 있으면 그대로 리턴

    res = -INF;
    // 도보로 이동 가능하면 진행
    if(time >= wt[here]) {
        // 금액을 들고 다니면 시간을 중간에 다 써버린 경우에 계산기 꼬일 수 있음. 밖에서 더해야 정확한 계산 가능
        res = max(res, go(here + 1, time - wt[here]) + wm[here]);
    }
    // 자전거로 이동 가능하면 진행
    if(time >= bt[here]) {
        res = max(res, go(here + 1, time - bt[here]) + bm[here]);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> wt[i] >> wm[i] >> bt[i] >> bm[i];
    }   // end of for

    cout << go(0, K) << '\n';

    return 0;
}