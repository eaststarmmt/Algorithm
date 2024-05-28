#include <string>
#include <vector>

using namespace std;

int cnt[2];

void count(vector<string>& board) {
    // 카운팅
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] == 'O') cnt[0]++;
            else if(board[i][j] == 'X') cnt[1]++;
        }   // end of for j
    }   // end of for i

}

bool win_check(vector<string>& board, char c) {
    int win = 0;
    for(int i = 0; i < 3; i++) {    // 가로 체크
        win = 0;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == c) win++;
        }
        if(win == 3) return true;
    }

    for(int i = 0; i < 3; i++) {    // 세로 체크
        win = 0;
        for(int j = 0; j < 3; j++) {
            if(board[j][i] == c) win++;
        }
        if(win == 3) return true;
    }

    win = 0;
    for(int i = 0; i < 3; i++) {    // 왼쪽 대각선 체크
        if(board[i][i] == c) win++;
    }

    if(win == 3) return true;

    win = 0;
    for(int i = 2; i >= 0; i--) {   // 오른쪽 대각선 체크
        if(board[2 - i][i] == c) win++;
    }
    if(win == 3) return true;

    return false;
}

int solution(vector<string> board) {
    int answer = 1;

    count(board);
    if(!cnt[0] && !cnt[1]) return 1;
    if(cnt[0] > cnt[1] + 1) return 0;
    if(cnt[1] > cnt[0]) return 0;

    bool o = win_check(board, 'O');
    bool x = win_check(board, 'X');

    if(o && x) return 0;    // 둘다 승리인 경우 불가능
    if(o && cnt[0] != cnt[1] + 1) return 0; // O가 이겼는데 O 갯수가 한개가 더 많은게 아닌 경우
    if(x && cnt[0] != cnt[1]) return 0; // X가 이겼는데 갯수가 같지 않은 경우
    return answer;
}