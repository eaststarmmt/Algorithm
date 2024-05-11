#include <string>
#include <vector>
#include <map>

using namespace std;
int R, C, r, c;
map<char, int> dr = {
        {'N', -1},
        {'S', 1},
        {'W', 0},
        {'E', 0}
};

map<char, int> dc = {
        {'N', 0},
        {'S', 0},
        {'W', -1},
        {'E', 1}
};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    R = park.size();
    C = park[0].size();

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(park[i][j] == 'S') {
                r = i;
                c = j;
            }
        }   // end of for j
    }   // end of for i

    for(string s: routes) {
        char d = s[0];
        int x = (s[2] - '0');
        int nr = r;
        int nc = c;
        bool flag = true;
        for(int i = 0; i < x; i++) {
            nr += dr[d];
            nc += dc[d];

            if(nr < 0 || nr >= R || nc < 0 || nc >= C) {
                nr = r;
                nc = c;
                break;
            }
            if(park[nr][nc] == 'X') {
                nr = r;
                nc = c;
                break;
            }
        }   // end of for i

        r = nr;
        c = nc;
    }   // end of for routres

    answer = {r, c};
    return answer;
}