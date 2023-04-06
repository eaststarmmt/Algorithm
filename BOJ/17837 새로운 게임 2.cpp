#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Horse{
    int r, c, dir;
};

int a[16][16];
vector<int> chess[16][16];
vector<Horse> horse;
int N, K;
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

bool map_check(int r, int c){
    return r < 1 or r > N or c < 1 or c > N;
}

void move_horse(vector<int> horse_list, int nr, int nc) {
    // 현 위치 저장. 아무 인덱스나 잡아도 똑같음
    int r = horse[horse_list[0]].r;
    int c = horse[horse_list[0]].c;

    // 기존의 위치에서 제거
    for(int i = 0; i < horse_list.size(); i++) {
        chess[r][c].pop_back();
    }   // end of for horse pop

    // 다음 위치에 말 올려놓고 말 정보 갱신하기
    for(int i : horse_list) {
        chess[nr][nc].push_back(i);
        horse[i].r = nr;
        horse[i].c = nc;
    }   // end of for
}

int move(int idx) {
    int r = horse[idx].r;
    int c = horse[idx].c;
    int dir = horse[idx].dir;
    int stair = find(chess[r][c].begin(), chess[r][c].end(), idx) - chess[r][c].begin();
    vector<int> horse_list(chess[r][c].begin() + stair, chess[r][c].end()); // idx 말부터 위에 있는 말들

    int nr = r + dr[dir];
    int nc = c + dc[dir];

    if (map_check(nr, nc) or a[nr][nc] == 2) {  // 파란색 칸이거나 맵을 벗어난 경우. 방향 변경하기
        int back = (dir ^ 1);   // 반대방향
        horse[idx].dir = back;
        nr = r + dr[back];
        nc = c + dc[back];

        if(map_check(nr, nc) or a[nr][nc] == 2) {   // 뒤 방향도 마찬가지면 이동하지 않는다
            return chess[r][c].size();
        }
    }

    if (a[nr][nc] == 1) {   // 빨간색 칸이면 현재 말들 순서 변경
        reverse(horse_list.begin(), horse_list.end());
    }

    move_horse(horse_list, nr, nc);
    return chess[nr][nc].size();

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }   // end of for j
    }   // end of for i

    for(int i = 0; i < K; i++) {
        int r, c, dir;
        cin >> r >> c >> dir;
        horse.push_back({r, c, --dir});
        chess[r][c].push_back(i);
    }   // end of for horse

    int turn = 0;

    while (++turn < 1000) {
        for(int i = 0; i < K; i++) {
            int size = move(i);
            if (size >= 4) {    // 한 칸에 4개 이상 쌓여있으면 종료
                cout << turn << "\n";
                return 0;
            }
        }   // end of for
    }   // end of while

    cout << "-1\n";
}