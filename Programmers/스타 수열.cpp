#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cnt[500004];

int get_res(int x, vector<int>& a) {
    int res = 0;    // 부분수열의 원소에 포함될 순서쌍

    for(int i = 0; i < a.size() - 1; i++) {
        if(a[i] != x && a[i + 1] != x) continue;    // 공통분모로 정한 값에 포함 안되어 있으면 무시
        if(a[i] == a[i + 1]) continue;  // 연속된 숫자가 같으면 무시

        // 해당 조건을 만족하는 경우
        res++;  // 수열에 포함될 순서쌍의 개수 하나 추가
        i++;    // i + 1을 포함 시켰으므로 다음 숫자로 넘어가야 됨
    }

    return res;
}

int solution(vector<int> a) {
    int answer = 0;

    for(int x : a) {    // 숫자 몇번씩 나왔는지 카운팅
        cnt[x]++;
    }   // end of for a

    for(int i = 0; i < a.size(); i++) {     // 공통분모가 될 값
        int x = cnt[i];   // i가 몇번 나왔는지
        if(x <= answer) continue;   // i가 현재 답보다 적게 나왔으면 무시.

        int res = get_res(i, a);
        answer = max(res, answer);
    }   // end of for
    answer <<= 1;   // 순서쌍이므로 *2 된 만큼 길이가 됨
    return answer;
}