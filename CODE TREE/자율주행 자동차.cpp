#include<iostream>
#include<algorithm>

using namespace std;

int a[54][54], visited[54][54];
int N, M, r, c, d, res;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int get_dir(int x) {
    // 왼쪽으로 회전. 음수면 4 더해서 인덱스 조정
    return x < 0 ? x + 4 : x;
}

bool move(int nr, int nc) {
    // 이동
    r = nr;
    c = nc;
    // 방문한 적 없으면 면적 증가
    if(!visited[nr][nc]) {
        res++;
        visited[nr][nc] = 1;
    }

    return true;
}

bool go_left() {
    bool is_possible = false;
    // 왼쪽으로 방향 돌리기
    for(int i = 1; i <= 4; i++) {
        // 왼쪽으로 회전. 음수면 4 더해서 인덱스 조정
        int nd = get_dir(d - i);

        int nr = r + dr[nd];
        int nc = c + dc[nd];

        // 이동 안되는 경우
        if(visited[nr][nc]) continue;
        if(a[nr][nc]) continue;

        // 이동
        move(nr, nc);
        d = nd;
        is_possible = true;
        break;
    }   // end of for dir
    return is_possible;
}

bool go_back() {
    int nd = get_dir(d - 2);
    int nr = r + dr[nd];
    int nc = c + dc[nd];
    if(a[nr][nc]) return false;

    move(nr, nc);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> r >> c >> d;

    visited[r][c] = 1;
    res++;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> a[i][j];
        }   // end of for i
    }   // end of for j

    while(true) {
        // 왼쪽으로 이동
        if(go_left()) continue;
        // 뒤로 이동
        if(go_back()) continue;
        break;
    }
    cout << res << '\n';
}