#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Info {
    string name;
    int start, playtime;
};

vector<Info> v;
stack<pair<string, int>> stk;    // 중단 된 작업 저장할 스택

int time_to_int(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3));

    return hour * 60 + minute;
}

bool cmp(Info &i1, Info &i2) {  // 시작시간으로 오름차순 정렬
    return i1.start < i2.start;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    // 시간을 정수형으로 변경하여 새로 저장.
    for(vector<string> plan : plans) {
        string name = plan[0];
        int start = time_to_int(plan[1]);
        int playtime = stoi(plan[2]);

        v.push_back({name, start, playtime});
    }   // end of for

    sort(v.begin(), v.end(), cmp);

    int cur = 0;

    for(int i = 0; i < v.size(); i++) {
        int start = v[i].start;

        while(!stk.empty() && cur < start) {
            string name = stk.top().first;
            int pre_playtime = stk.top().second;
            stk.pop();

            // 최근에 멈춘 작업을 다음 작업 시작 전까지 돌렸을때 남은 작업 시간
            int remain = max(0, pre_playtime - (start - cur));
            cur += pre_playtime - remain;   // 시간의 경과

            if(remain == 0) { // 다음 작업 전에 끝낼 수 있는 경우
                answer.push_back(name);
                continue;
            }

            stk.push({name, remain});
        }   // end of while

        if(stk.empty()) cur = v[i].start;  // 중단된 작업이 다 끝난 경우 현재 시간을 새로운 작업 시작 시간으로 변경
        stk.push({v[i].name, v[i].playtime});
    }   // end of for

    while(!stk.empty()) {
        string name = stk.top().first;
        stk.pop();
        answer.push_back(name);
    }   // end of while

    return answer;
}