#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1e9

using namespace std;

struct Info {
    int r, c, dir;
};

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int R, C, res = INF;
int a[8][8], visited[8][8], temp[8][8];
vector<Info> horse;

void mark_in_map(Info i, vector<int> dir) {
    for(int d : dir) {
        int r = i.r;
        int c = i.c;
        while(true) {
            // 말이 바라보고 있는 방향에서 진행방향 더하기
            r += dr[(d + i.dir) % 4];
            c = c + dc[(d + i.dir) % 4];
            // 범위 벗어나면 종료
            if(r < 0 || r >= R || c < 0 || c >= C) break;
            // 상대편의 말은 뛰어넘을 수 없으니 종료
            if(a[r][c] == 6) break;
            // 이미 둔 곳은 뛰어 넘는 경우도 있을 수 있으니 일단 무시
            if(visited[r][c]) continue;
            // 표시
            visited[r][c] = 1;
        }   // end of while
    }
}

void mark(Info i) {
    vector<int> dir;
    // 말 번호별로 이동 가능 방향 넣어서 표시하는 함수로 값 넘기기
    int num = a[i.r][i.c];
    if(num == 1) {
        dir = {0};
    } else if(num == 2) {
        dir = {1, 3};
    } else if(num == 3) {
        dir = {0, 1};
    } else if(num == 4) {
        dir = {0, 1, 3};
    } else if(num == 5) {
        dir = {0, 1, 2, 3};
    }

    mark_in_map(i, dir);
}

int count() {
    memcpy(visited, temp, sizeof(visited));
    // 지금까지 방향에 맞게 지도에 표시
    for(Info i : horse) {
        mark(i);
    }   // end of for

    int cnt = 0;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(!visited[i][j]) cnt++;
        }   // end of for j
    }   // end of for i

    return cnt;
}

void go(int cnt) {
    if(cnt == horse.size()) {
        res = min(res, count());
        return;
    }

    int& dir = horse[cnt].dir;

    for(int d = 0; d < 4; d++) {
        dir = (dir + d) % 4;
        go(cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> a[i][j];
            // 체스말 정보 저장
            if(a[i][j] >= 1 && a[i][j] <= 5) {
                horse.push_back({i, j});
            }
            // 이동 할 수 있는 위치 체크
            if(a[i][j] >= 1) temp[i][j] = 1;
        }   // end of for j
    }   // end of for i

    go(0);

    cout << res << '\n';

    return 0;
}