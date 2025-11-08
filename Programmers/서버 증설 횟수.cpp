#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<pair<int, int>> Q;    // 반납 시간, 증설 서버 수
    int server = 0;    // 현재 증설 되어 있는 서버 수

    for(int i = 0; i < players.size(); i++) {
        if(!Q.empty() && Q.front().first == i) {    // 서버 시간 다 된 경우
            server -= Q.front().second;
            Q.pop();
        }

        int player = players[i];
        int required = player / m;

        if(server >= required) continue;

        answer += required - server;
        Q.push({i + k, required - server});
        server = required;

    }
    return answer;
}