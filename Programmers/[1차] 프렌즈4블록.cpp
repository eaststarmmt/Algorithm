#include <string>
#include <vector>
#include <set>
using namespace std;

struct Info {
    int r, c;
};

int dr[] = {0, 1, 1};   // 우 하 우하
int dc[] = {1, 0, 1};

int checkDown(int i, int j, vector<string>& board, int m) {
    while(i < m) {
        if(board[i][j] != ' ') {
            return i - 1;
        }
        i++;
    }
    return m - 1;   // 끝까지 다 내려가는 경우
}

void down(int i, int j, vector<string>& board, int target) {
    for(int r = i; r >= 0; r--, target--) {
        if(board[r][j] == ' ') break;
        board[target][j] = board[r][j];
        board[r][j] = ' ';
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true) {
        set<pair<int, int>> info;     // 중복 제거를 위해 set 사용
        for(int r = 0; r < m - 1; r++) {
            for(int c = 0; c < n - 1; c++) {
                bool flag = true;
                if(board[r][c] == ' ') continue;    // 하나라도 공백이면 무시
                for(int k = 0; k < 3; k++) {    // 세개중 하나라도 다르면 무시 
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if((board[nr][nc] != board[r][c])) {
                        flag = false;
                        break;
                    }   
                }   // end of for k
                if(!flag) continue;
                info.insert({r, c});
                for(int i = 0; i < 3; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    info.insert({nr, nc});
                }
            }   // end of for c
        }   // end of for r
        // 지울게 없으면 종료
        if(info.empty()) 
            break;
        // 지워지는 블록 개수 저장
        answer += info.size();
        
        // 삭제 작업
        for(auto i : info) {
            board[i.first][i.second] = ' ';
        }   // end of for
        
        // 매꾸기
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == ' ' || board[i + 1][j] != ' ') continue;
                int target = checkDown(i + 1, j, board, m);
                if(target == -1) continue;

                down(i, j, board, target);  
            }
        }
    }   // end of while
    return answer;
}