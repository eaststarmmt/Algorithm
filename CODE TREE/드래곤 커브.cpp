#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
int N, R, C, d, g;
int a[104][104];
vector<int> dragon_curve[4][11];    // 드래곤 커브의 시작방향, 차수에 따른 방향 순서 저장

void set_dragon_curve() {
    for(int start = 0; start < 4; start++) {
        // 0차수랑 1차수 미리 저장
        dragon_curve[start][0].push_back(start);
        dragon_curve[start][1].push_back((start + 1) % 4);

        for(int i = 2; i <= 10; i++) {  // 2차수부터 저장
            for(int j = i - 1; j >= 0; j--) {
                int size = dragon_curve[start][j].size();   // 전 차수 역순의 반시계방향이므로 사이즈 같음
                for (int k = size - 1; k >= 0; k--) {
                    dragon_curve[start][i].push_back((dragon_curve[start][j][k] + 1) % 4);
                }   // end of for k
            }   // end of for j
        }   // end of for i
    }   // end of for start
}

void mark(int r, int c) {
    a[r][c] = 1;
    for(int i = 0; i <= g; i++) {   // 0차수부터 주어진 차수까지 표시
        for(int dir : dragon_curve[d][i]) { // 미리 저장해놓은 방향 순서대로 꺼내서 표시
            r += dr[dir];
            c += dc[dir];
            a[r][c] = 1;
        }
    }   // end of for i
}

int get_res() {
    int cnt = 0;
    for(int i = 0; i < 99; i++) {
        for(int j = 0; j < 99; j++) {
            if(a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) cnt++;
        }   // end of for j
    }   // end of for i
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    set_dragon_curve();

    for(int i = 0; i < N; i++) {
        cin >> R >> C >> d >> g;
        mark(R, C);
    }

    cout << get_res() << '\n';
}