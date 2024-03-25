#include <iostream>
#include <string>
#include <algorithm>
#define INF 1e9
using namespace std;

int dp[2504][2504];  // 펠린드롬 체크용. [시작점][길이]
int dp2[2504];  // 최소 펠린드롬 개수 체크용
string s;

int go(int here) {
    if(here == s.size()) return 0;  // 문자열이 끝났으면 종료
    if(dp2[here] != INF) return dp2[here];  // 이미 저장된 값이 있으면 활용
    int &res = dp2[here];

    // here부터 펠린드롬 길이 하나씩 늘려보며 최솟값 찾기
    // i는 here부터 시작되는 펠린드롬의 길이
    for(int i = 1; i + here <= s.size(); i++) {
        // here까지 갔다온 개수 + 현재 위치를 포함해야 하므로 + 1
        // 길이 하나씩 늘려가며 나온 값 중 최솟값 저장
        if(dp[here][i]) res = min(res, go(here + i) + 1);
    }   // end of for

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    // 길이가 1인 문자는 펠린드롬이므로 체크
    for(int i = 0; i < s.size(); i++) {
        dp[i][1] = 1;
    }   // end of for

    // 두 글자가 연속으로 나오면 크기가 2인 펠린드롬 체크
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] == s[i + 1]) dp[i][2] = 1;
    }   // end of for

    // 사이즈 기준으로 하나씩 늘리면서 펠린드롬인지 체크.
    for(int size = 3; size <= s.size(); size++) {
        for(int i = 0; i + size <= s.size(); i++) {
            // 이미 펠린드롬이면 양 끝에 같은 글자가 있으면 그거도 펠린드롬임. 이런 개념으로 확장하면서 체크
            // ex. x...x, ox...xo
            if(s[i] == s[i + size - 1] && dp[i + 1][size - 2]) dp[i][size] = 1;
        }   // end of for i
    }   // end of for size

    fill(dp2, dp2 + 2504, INF);

    cout << go(0) << '\n';

    return 0;
}