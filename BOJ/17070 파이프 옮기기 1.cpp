#include<iostream>
#include<algorithm>

using namespace std;

int N, a[20][20], dp[20][20][3], res;    // 방향 0, 1, 2: 왼쪽, 대각선, 아래

bool check(int i, int j, int dir) {      // dir은 현재 가려는 방향
    if(dir == 0 || dir == 2) {  // 왼쪽과 아래는 가려는 곳만 빈 칸이면 됨
        if(a[i][j] == 0) return true;
    } else if(dir == 1) {       // 대각인 경우 위랑 왼쪽이 비어 있어야 됨
        if(a[i][j] == 0 && a[i - 1][j] == 0 && a[i][j - 1] == 0) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }

    dp[1][2][0] = 1;    // 시작방향

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            // 이전에 오른쪽 방향으로 밀고 있던 경우
            if(check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

            // 아래 방향으로 밀고 있던 경우
            if(check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
            if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

            // 대각으로 밀고 있던 경우
            if(check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
            if(check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
            if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
        }   // end of for j
    }   // end of for i

    // 방향 세개 이므로 다 더하기
    for(int i = 0; i < 3; i++) {
        res += dp[N][N][i];
    }

    cout << res << "\n";

    return 0;
}