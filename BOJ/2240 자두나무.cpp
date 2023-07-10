#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1e9
using namespace std;

int T, W;
int a[1004], dp[1004][2][34];

int dynamic(int t, int tree, int cnt) {     // 시간, 몇번 나무인지, 이동 남은 횟수
    // 기저조건
    if(cnt < 0) return -INF;    // 움직일 수 있는 횟수를 넘겼으면 값 안나오게 -INF 리턴
    if(t == T) return cnt == 0 ? 0 : -INF;  // 시간 넘어갔으면 연산에 영향 주면 안됨. 그런데 움직일 수 있는 횟수가 넘어갔으면 값이 되면 안됨

    // 메모이제이션
    int &res = dp[t][tree][cnt];

    if(~res) return res;    // -1이 아니면 더 이상 계산하지 말고 값 리턴

    // 이동 하는 경우와 하지 않는 경우 중 큰 값 리턴. 비교 연산자로 같은 경우 1, 다른 경우 0이 더해짐
    return res = max(dynamic(t + 1, tree, cnt), dynamic(t + 1, tree ^ 1, cnt - 1)) + (tree == a[t] - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 초기화
    memset(dp, -1, sizeof(dp));

    cin >> T >> W;

    for(int i = 0; i < T; i++) {
        cin >> a[i];
    }   // end of for i

    cout << max(dynamic(0, 0, W), dynamic(0, 1, W - 1));

}