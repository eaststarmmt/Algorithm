#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct cmp {    // 퇴실시간 기준 오름차순
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // 퇴실시간 기준 오름차순 해줄 우선순위 큐
vector<pair<int, int>> a;   // 시간 int로 변환해서 넣을 벡터. <시작시간, 끝시간>

int string_to_int(string s) {
    int hour = stoi(s.substr(0, 2));
    int minu = stoi(s.substr(3));

    return (hour * 60) + minu;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    // 계산하기 쉽게 시간을 숫자 단위로 변경
    for(int i = 0; i < book_time.size(); i++) {
        // 끝나고 10분 청소시간 필요하므로 10분 더해서 저장
        a.push_back({string_to_int(book_time[i][0]), string_to_int(book_time[i][1]) + 10});
    }   // end of for i
    // 시작 시간 기준 오름차순 정렬. 시작 순서대로 확인하지 않고 끝시간만을 비교하면 큐에서 빠져서 적게 카운팅 될 수 있음
    sort(a.begin(), a.end());

    for(pair<int, int> t : a) {
        if(pq.empty()) {     // 사용중인 객실 없으면 push
            pq.push(t);
        } else if(pq.top().second > t.first) {    // 시간 겹치는 경우. 가독성을 위해 조건 분리. 오름차순이라 큐에 다음 값도 어차피 겹침
            pq.push(t);
        } else {    // 사용중이던 방 청소 끝난 경우 기존 대실을 빼고 새로운 대실을 넣어줌
            pq.pop();    // 여러개가 끝나는 경우도 있을 수 있지만 최댓값만 확인하면 되므로 고려하지 않음
            pq.push(t);
        }
        // 사용중인 방의 개수 최댓값 갱신
        answer = max((int)pq.size(), answer);
    }
    return answer;
}