#include <string>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> max_res;

pair<int, int> get_res(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& ratio) {
    int cnt = 0;    // 가입자 수 카운팅 할 변수
    int res_sum = 0;    // 총 구매 가격
    for(vector<int> user : users) {     // 사람별로 구매 및 가입 여부 판단
        int sum = 0;
        int min_ratio = user[0];
        int limit = user[1];
        for(int i = 0; i < emoticons.size(); i++) {
            int price = emoticons[i];
            if(ratio[i] < min_ratio) continue;  // 할인 조건이 달성 안되면 구매 안함
            sum += price * (100 - ratio[i]) / 100;
        }   // end of for emoticons
        if(sum >= limit) cnt++;     // 구매 가격 조건을 넘기면 구독 카운팅 증가
        else res_sum += sum;    // 조건을 못넘겼으면 매출액 증가
    }   // end of for users

    return {cnt, res_sum};
}

void go(vector<vector<int>>& users, vector<int>& emoticons, vector<int> ratio) {
    if(ratio.size() == emoticons.size()) {
        pair<int, int> res = get_res(users, emoticons, ratio);
        if(res.first > max_res.first) max_res = res;    // 구독자 수 많은걸로 갱신
        else if(res.first == max_res.first) max_res.second = max(res.second, max_res.second);   // 구독자 같으면 매출액 최댓값으로 갱신
        return;
    }

    int idx = ratio.size();     // 이모티콘의 인덱스를 가리키기 위한 변수

    for(int i = 1; i <= 4; i++) {
        ratio.push_back(i * 10);
        go(users, emoticons, ratio);
        ratio.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    go(users, emoticons, vector<int>());

    answer = {max_res.first, max_res.second};
    return answer;
}