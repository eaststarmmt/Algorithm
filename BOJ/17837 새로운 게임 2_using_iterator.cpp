#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Info {
    int r, c, d;
};

int a[16][16], N, K;
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};
vector<int> horse[16][16];
vector<Info> horse_status;

void move(int r, int c, int d, int idx) {
    int nr = r + dr[d];
    int nc = c + dc[d];

    // 범위 넘어갔거나 파란색인지 체크
    if(nr < 0 || nr >= N || nc < 0 || nc >= N || a[nr][nc] == 2) {
        int back = d ^ 1;   // 반대 방향
        horse_status[idx].d = back;
        nr = r + dr[back];
        nc = c + dc[back];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N || a[nr][nc] == 2) return; // 반대방향도 같은 상황이면 이동 안함
    }

    //현재 말 몇층에 있는지 확인
    auto pos = find(horse[r][c].begin(), horse[r][c].end(), idx);
    if(a[nr][nc] == 1) {    // 빨간색이면 현재 말부터 위에 말들 순서 뒤집기
        reverse(pos, horse[r][c].end());
    }
    // 말 이동
    for(auto it = pos; it != horse[r][c].end(); it++) {
        horse[nr][nc].push_back(*it);
        horse_status[*it].r = nr;
        horse_status[*it].c = nc;
    }   // end of for pos

    // 현재 말 부터 그 위에 있던 말들 기존 위치에서 삭제
    horse[r][c].erase(pos, horse[r][c].end());
}

bool is_over() {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            if(horse[i][j].size() >= 4) return true;
        }
    }
    return false;
}

bool simul() {
    for(int i = 0; i < horse_status.size(); i++) {
        int r = horse_status[i].r;
        int c = horse_status[i].c;
        int d = horse_status[i].d;
        move(r, c, d, i);

        if(is_over()) return true;  // 게임 끝났는지 여부 리턴
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }   // end of for j
    }   // end of for i

    for(int i = 0; i < K; i++) {
        int r, c, d;
        cin >> r >> c >> d;
        horse_status.push_back({--r, --c, --d});
        horse[r][c].push_back(i);
    }   // end of for

    int cnt = 0;
    while(++cnt <= 1000) {
        if(simul()) {
            cout << cnt << "\n";
            return 0;
        }
    }   // end of for

    cout << -1 << "\n";
    return 0;
}