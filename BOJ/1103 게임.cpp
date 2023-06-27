#include <iostream>
#include <algorithm>
using namespace std;
int R, C, a[54][54], dp[54][54], visited[54][54];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool check(int r, int c) {  // 지도 범위 벗어나거나 구멍인 경우
    if(r < 1 || r > R || c < 1 || c > C || a[r][c] == 'H') return false;
    return true;
}

int solve(int r, int c) {
    if(!check(r, c)) return 0;  // 게임이 종료 된 경우
    if(visited[r][c]) {     // 무한번 갈 수 있는 경우
        cout << -1 << "\n";
        exit(0);
    }
    // 메모이제이션
    int &res = dp[r][c];
    if(res) return res;     // 값이 있는 경우 그 값 리턴. 한 점을 기준으로 다른곳으로 퍼져서 다녀온 결과를 저장하는 방식이기 때문에 갱신될 일 없음

    visited[r][c] = 1;  // 루프를 확인하기 위해 방문 체크

    for(int i = 0; i < 4; i++) {
        int val = a[r][c] - '0';
        int nr = r + dr[i] * val;
        int nc = c + dc[i] * val;

        res = max(res, solve(nr, nc) + 1);  // 최댓값 갱신
    }   // end of for

    visited[r][c] = 0;  // 끝난 후 방문 체크 해제

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for(int i = 1; i <= R; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= C; j++) {
            a[i][j] = s[j - 1];
        }   // end of for j
    }   // end of for i

    cout << solve(1, 1) << "\n";
}

/*
10 10
12H12H12H1
2H12H12H12
H12H12H12H
12H12H12H1
2H12H12H12
H12H12H12H
12H12H12H1
2H12H12H12
H12H12H12H
12H12H12H1
 */