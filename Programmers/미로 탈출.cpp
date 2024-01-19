#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int R, C, start_r, start_c;
int visited[104][104];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& maps, int r, int c, char target) {
    int res = -1;
    queue<pair<int, int>> Q;
    Q.push({r, c});
    visited[r][c] = 1;

    while(!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(visited[nr][nc]) continue;
            if(maps[nr][nc] == 'X') continue;

            if(maps[nr][nc] == target) {
                start_r = nr;
                start_c = nc;
                return visited[r][c];
            }

            visited[nr][nc] = visited[r][c] + 1;
            Q.push({nr, nc});
        }
    }   // end of while
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    R = maps.size();
    C = maps[0].size();

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(maps[i][j] == 'S') {
                start_r = i;
                start_c = j;
            }
        }
    }
    int start_to_labber = bfs(maps, start_r, start_c, 'L');
    int labber_to_exit = 0;
    if(start_to_labber > 0) {
        memset(visited, 0, sizeof(visited));
        labber_to_exit = bfs(maps, start_r, start_c, 'E');
    }

    answer = start_to_labber == -1 || labber_to_exit == -1 ? -1 : start_to_labber + labber_to_exit;
    return answer;
}