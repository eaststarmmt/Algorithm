#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int R, C;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};
int visited[104][104];

pair<int, int> roll(vector<string>& a, pair<int, int> pos, int d) {
    int r = pos.first;
    int c = pos.second;

    while(true) {
        int nr = r + dr[d];
        int nc = c + dc[d];

        if(nr < 0 || nr >= R || nc < 0 || nc >= C) break;
        if(a[nr][nc] == 'D') break;
        r = nr;
        c = nc;
    }
    return make_pair(r, c);
}

int bfs(vector<string>& a, pair<int, int> start) {
    int res = -1;
    queue<pair<int, int>> Q({start});
    visited[start.first][start.second] = 1;

    while(!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++) {
            pair<int, int> npos = roll(a, {r, c}, i);
            int nr = npos.first;
            int nc = npos.second;

            if(visited[nr][nc]) continue;
            if(a[nr][nc] == 'G') return visited[r][c];
            visited[nr][nc] = visited[r][c] + 1;
            Q.push(npos);
        }

    }   // end of while

    return res;
}

int solution(vector<string> board) {
    R = board.size();
    C = board[0].size();
    pair<int, int> start;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            // 시작 위치 저장
            if(board[i][j] == 'R') {
                start.first = i;
                start.second = j;
            }
        }
    }

    int answer = bfs(board, start);
    return answer;
}