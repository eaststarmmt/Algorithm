#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;

    sort(targets.begin(), targets.end(), cmp);  // 라인 스위핑을 하기 위해 끝점 기준 정렬

    int hi = -1;    // 기준이 되는 끝점을 저장할 변수.끝점 기준으로 확인하기 때문에 첫번째 라인은 무조건 카운팅이 되도록 -1로 시작

    // 미사일의 끝점을 잡고 다음 미사일의 시작점이 끝점보다 작으면 같이 요격 가능. 끝점 오름차순이기 때문에.
    for(vector<int> v : targets) {
        int s = v[0];
        int e = v[1];

        // 미사일 시작점이 이전 미사일의 끝점보다 뒤에 있는 경우.
        // 이 경우는 같이 요격이 불가능하므로 미사일 카운팅 하고 새로 끝점으로 잡아줌.
        // 개구간이라 같아도 같이 요격 불가.
        if(s >= hi) {
            answer++;
            hi = e;
        }
    }   // end of for targets

    return answer;
}