#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int a[54][54], visited[54][54];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int res, N, L, R;
vector<pair<int, int>> egg_list;

void dfs(int r, int c) {
    visited[r][c] = 1;
    egg_list.push_back({r, c});
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(visited[nr][nc]) continue;
        if(abs(a[r][c] - a[nr][nc]) > R || abs(a[r][c] - a[nr][nc]) < L) continue;

        dfs(nr, nc);
    }
}

void move_egg() {
    int sum = 0;

    // 이동할 계란 총 합 구하기
    for(pair<int, int> p: egg_list) {
        sum += a[p.first][p.second];
    }    // end of for egg_list

    int egg = sum / egg_list.size();

    // 계란 분배
    for(pair<int, int> p: egg_list) {
        a[p.first][p.second] = egg;
    }    // end of for egg_list
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }   // end of for j
    }   // end of for i

    bool flag = true;   // 이동 가능하면 true 불가능하면 false

    while(flag) {
        memset(visited, 0, sizeof(visited));
        flag = false;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(visited[i][j]) {    // 방문한적 없는 경우만 dfs 실행
                    continue;
                }
                egg_list.clear();    // 이동할 계란 위치 담을 벡터 초기화
                dfs(i, j);
                if(egg_list.size() <= 1) continue;   // 이동할 계란 한개면 이동 안하는 상황

                move_egg();
                flag = true;    // 이동이 가능했으므로 다음 이동 확인하기 위해 플래그 표시
            }   // end of for j
        }   // end of for i
        if(flag) res++;
    }   // end of while

    cout << res << '\n';
    return 0;
}