#include <iostream>
#include <algorithm>

using namespace std;

int N, M, C, a[20], dp[20][1 << 14][24];    // dp 가방 인덱스, 넣은 보석, 인덱스에 해당하는 가방의 무게

int go(int here, int jam, int capacity) {   // 가방 인덱스, 보석 보유 상황, 현재 가방의 용량
    if(here == M) return 0;     // 가방 끝까지 다 확인 했으면 종료

    int &res = dp[here][jam][capacity];
    if(res) return res;

    // 현재 가방에 안 넣는 방법.capacity는 가방 별로 주어지는 수용량이므로 다음 가방으로 넘어갈때 초기화 해야 됨
    res = go(here + 1, jam, C);

    for(int i = 0; i < N; i++) {
        bool is_here = jam & (1 << i);  // 현재 담은 보석 상황과 i번째 보석을 &연산을 이용하여 체크
        // i번째 보석 안들어있고 현재 가방에 보석을 담을 수 있는 공간이 있는 경우
        if(!is_here && capacity - a[i] >= 0) {
            res = max(res, go(here, jam | (1 << i), capacity - a[i]) + 1);
        }
    }   // end of for

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> C;

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }   // end of for

    cout << go(0, 0, C) << '\n';
    return 0;
}