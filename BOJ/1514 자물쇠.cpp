#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 1e9

using namespace std;

int dp[104][10][10][10][2];    // 인덱스, 첫번째, 두번째, 세번째, 방향
int cur[104], a[104];
int N;

// 회전 이동 구현
int move(int x) {
    return (x < 0) ? 10 + (x % 10) : x % 10;
}

// 앞칸부터 하나씩 맞춰 가면서 확인
int go(int pos, int x, int y, int z, int flag) {    // x는 현재 위치의 이동 칸 수, y, z 는 다음, 다다음 위치의 이동 칸 수
    if(pos == N) return 0;
    int &res = dp[pos][x][y][z][flag];
    if(res != -1) return res;
    if(move(x + cur[pos]) == a[pos]) return res = min(go(pos + 1, y, z, 0, 0), go(pos + 1, y, z, 0, 1));

    res = INF;
    int dir = flag ? 1 : -1;    // 시계방향인지 반대방향인지 사용하기 편하게 저장
    // 한번에 1 ~ 3칸 이동 가능. 한번에 1 ~ 3개 같이 이동 가능
    for(int i = 1; i <= 3; i++) {
        // 한 번씩 이동하므로 1 + 재귀 형태로 계산
        res = min(res, 1 + go(pos, move(x + i * dir), y, z, flag));
        res = min(res, 1 + go(pos, move(x + i * dir), move(y + i * dir), z, flag));
        res = min(res, 1 + go(pos, move(x + i * dir), move(y + i * dir), move(z + i * dir), flag));
    }   // end of for

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < N; i++) {
        scanf("%1d", &cur[i]);
    }   // end of for

    for(int i = 0; i < N; i++) {
        scanf("%1d", &a[i]);
    }   // end of for

    cout << min(go(0, 0, 0, 0, 0), go(0, 0, 0, 0, 1)) << '\n';

}