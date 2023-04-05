#include<iostream>
#include<algorithm>
#define INF 1e9
using namespace std;

int R, C;
char a[14][14];
int res = INF;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void permu(pair<int, int> red, pair<int, int> blue, int cnt, int dir) {     // dir은 마지막에 이동한 방향
    // 10회 이하로 결과 나와야 됨
    if (cnt == 11) {
        return;
    }   // end of if

    for(int i = 0; i < 4; i++) {
        if (cnt != 1 && (i == dir or i == (dir ^ 1)) ) {  // 이미 진행한 방향은 막혀있을 것이고 반대방향은 지나온 방향이다
            continue;
        }

        pair<int, int> next_red = red;
        pair<int, int> next_blue = blue;
        bool flag = true;   // 파란색이 구멍에 들어가는지 체크할 flag

        // 파란색 이동
        while(1) {
            int nr = next_blue.first + dr[i];
            int nc = next_blue.second + dc[i];

            if(a[nr][nc] == '#') {  // 벽인 경우 이동 멈추기
                break;
            } else if(a[nr][nc] == 'O') {   // 파란색이 구멍으로 들어가는 경우 안되는 경우
                flag = false;
                break;
            }
            next_blue = {nr, nc};   // 좌표 갱신
        }   // end of while blue

        if (!flag) {    // 파란색이 구멍에 들어갔으면 무시
            continue;
        }
        // 빨간색 이동
        while(1) {
            int nr = next_red.first + dr[i];
            int nc = next_red.second + dc[i];


            if(a[nr][nc] == '#') {  // 벽인 경우 이동 멈추기
                break;
            } else if(a[nr][nc] == 'O') {   // 빨간색이 구멍으로 들어가는 res값 갱신
                res = min(res, cnt);
                return;
            }

            next_red = {nr, nc};    // 좌표 갱신

        }   // end of while

        if (next_red == red && next_blue == blue) continue;  // 이동 안한 경우는 굳이 할 필요 없음

        if(next_red == next_blue) {     // 빨간색과 파란색은 같은 공간에 겹칠 수 없음.
            // 두 구슬이 이동한 맨허튼 거리 구하기
            int red_dis = abs(next_red.first - red.first) + abs(next_red.second - red.second);
            int blue_dis = abs(next_blue.first - blue.first) + abs(next_blue.second - blue.second);

            int back = i ^ 1;

            // 둘중에 더 많은 거리를 이동한 구슬이 나중에 도착한 구슬이므로 뒤로 한칸 가야 됨
            if(red_dis > blue_dis) {
                next_red.first += dr[back];
                next_red.second += dc[back];
            } else {
                next_blue.first += dr[back];
                next_blue.second += dc[back];
            }
        }   // end of if 구슬 겹친 경우

        permu(next_red, next_blue, cnt + 1, i);
    }

}

int main() {
    scanf("%d %d", &R, &C);
    pair<int, int> red, blue;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %1c", &a[i][j]);
            if(a[i][j] == 'R') {
                red = {i, j};
            } else if(a[i][j] == 'B') {
                blue = {i, j};
            }

        }   // end of for j
    }   // end of for i

    permu(red, blue, 1, 0);
    if (res == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", res);
    }
}