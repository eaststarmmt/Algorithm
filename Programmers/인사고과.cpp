#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 시간복잡도 계산하기 어려운 문제

struct Info {
    int a, x, idx;  // 정렬할 점수, 비교할 점수, 인덱스
};

vector<Info> v, incentive;
int rank_table[100004];

bool a_sort(Info i1, Info i2) {
    if(i1.a == i2.a) return i1.x > i2.x;
    return i1.a > i2.a;
}

bool sum_sort(Info i1, Info i2) {
    return i1.a + i1.x > i2.a + i2.x;
}

int solution(vector<vector<int>> scores) {
    int answer = 0;

    for(int i = 0; i < scores.size(); i++) {
        int a = scores[i][0];
        int x = scores[i][1];
        v.push_back({a, x, i});
    }   // end of for scores

    sort(v.begin(), v.end(), a_sort);

    // 못받는 애들 걸러내는 로직

    for(int i = v.size() - 1; i >= 0; i--) {
        int x = v[i].x;
        int a = v[i].a;
        int idx = v[i].idx;
        bool is_incen = true;
        for(int j = i - 1; j >= 0; j--) {
            int y = v[j].x;
            int a2 = v[j].a;
            if(x >= y) continue;    // 인센 받는 경우는 작업 필요 없음
            if(a == a2) continue;   // x가 작더라도 둘이 같았으면 둘 다 작은 경우가 아님
            if(idx == 0) return -1;   // 완호 인센 못받는 경우
            is_incen = false;
            break;
        }   // end of for j
        if(is_incen) incentive.push_back(v[i]); // 인센티브 받을 수 있는 애들만 걸러내기
    }   // end of for i

    sort(incentive.begin(), incentive.end(), sum_sort);

    int cnt = 1;    // 현재 확인하는 점수 동점자 카운팅
    int prev_sum = incentive[0].a + incentive[0].x;   // 이전 점수의 합
    int prev_idx = incentive[0].idx;
    int now_rank = 1;
    rank_table[prev_idx] = 1;
    for(int i = 1; i < incentive.size(); i++) {
        int sum = incentive[i].a + incentive[i].x;
        int idx = incentive[i].idx;

        if(prev_sum == sum) {   // 동점자 나온 경우
            cnt++;
        } else {    // 동점자 아닌 경우. 카운팅 하던 부분들 초기화 해야 됨
            now_rank = cnt + rank_table[prev_idx];    // 이전 랭크 + 동점자 숫자가 다음 순위로 매겨질 사람
            cnt = 1;
            prev_sum = sum;
            prev_idx = idx;
        }
        rank_table[idx] = now_rank;
    }

    answer = rank_table[0];
    return answer;
}