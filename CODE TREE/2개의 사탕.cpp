#include <iostream>
#include <algorithm>
using namespace std;

char a[14][14];
int R, C, res = 1e9;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void permu(pair<int, int> red, pair<int, int> blue, int cnt, int dir) {
    if(cnt == 11) { // 10번 이내에 끝나야 하므로
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(cnt != 1 && ((dir ^ 1) == i || i == dir)) {  // 첫번째 이동이 아니라면 같은 방향과 반대 방향은 할 필요 없음
            continue;
        }

        pair<int, int> next_blue = blue;
        pair<int, int> next_red = red;
        bool flag = true;  // 파란공 들어가는지 체크용

        while(1) {
            int nr = next_blue.first + dr[i];
            int nc = next_blue.second + dc[i];

            if(a[nr][nc] == '#') break; // 장애물이 있는 경우 멈춤
            if(a[nr][nc] == 'O') {  // 파란사탕이 들어가면 안됨
                flag = false;
                break;
            }
            next_blue = {nr, nc};   // 장애 요소 없으면 갱신
        }   // end of while

        if(!flag) continue; // 파란사탕이 들어가는 경우면 확인 할 필요 없음

        while(1) {
            int nr = next_red.first + dr[i];
            int nc = next_red.second + dc[i];

            if(a[nr][nc] == 'O') {  // 빨간사탕이 구멍에 들어가면 res값 갱신 후 종료
                res = min(res, cnt);
                return;
            }
            if(a[nr][nc] == '#') break; // 장애물이 있는 경우 멈춤
            next_red = {nr, nc};
        }   // end of while

        if(next_red == red && next_blue == blue) continue;  // 이동하지 않았으면 굳이 카운팅 한개를 늘려서 진행할 필요가 없음
        if(next_red == next_blue) { // 두 사탕은 같은 위치에 존재 불가능
            // 두 사탕의 이동한 멘허튼 거리 구하기
            int red_dis = abs(next_red.first -red.first) + abs(next_red.second - red.second);
            int blue_dis = abs(next_blue.first - blue.first) + abs(next_blue.second - blue.second);

            int back = i  ^ 1; // 이동한 방향의 반대방향

            // 같은 줄에서 더 많이 이동했다는건 뒤에 있었다는 의미. 즉 뒤로 한칸 이동해서 이동 칸 수 맞춰주면 해결 됨
            if(red_dis > blue_dis) {
                next_red.first += dr[back];
                next_red.second += dc[back];
            } else {
                next_blue.first += dr[back];
                next_blue.second += dc[back];
            }
        }

        permu(next_red, next_blue, cnt + 1, i);
    }   // end of for
}

int main() {
    scanf("%d %d", &R, &C);
    pair<int, int> red, blue;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %1c", &a[i][j]);

            if(a[i][j] == 'B') blue = {i, j};
            if(a[i][j] == 'R') red = {i, j};
        }   // end of for j
    }   // end of for i

    permu(red, blue, 1, 0); // 처음 들어가자마자 바로 이동 시킬거라서 1부터 시작

    if(res == 1e9) {
        printf("-1\n");
    } else {
        printf("%d\n", res);
    }
    return 0;
}