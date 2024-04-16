#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int T, N;
// 숫자 만들기 위해 필요한 개수
int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[104];
string MAX = "111111111111111111111111111111111111111111111111119"; // n의 최대가 100이므로 1이 50개 가능

string get_max(int n) {
    string s;
    if(n & 1) {     // 홀수는 2진수가 1로 끝나기 때문에 1과 & 연산 시 반드시 1이 됨.
        s = "7";
        n -= 3;
    }
    for(int i = 0; i < n / 2; i++) {
        s += "1";
    }
    return s;
}

string get_min(string a, string b) {
    if(a.size() == b.size()) return a < b ? a : b;
    return a.size() < b.size() ? a : b;
}

// top down
string go(int here) {
    if(here == 0) return "";    // 성냥 없으면 종료
    string &res = dp[here];

    if(res != MAX) return res;  // 저장된 값 있으면 리턴

    for(int i = 0; i <= 9; i++) {
        if(here - a[i] < 0) continue;   // 성냥 모자른 경우
        if(here == N && i == 0) continue;   // 0으로 시작 불가능
        res = get_min(res, to_string(i) + go(here - a[i]));
    }   // end of for

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--) {
        cin >> N;
        fill(&dp[0], &dp[103], MAX);
        cout << go(N) << ' ' << get_max(N) << '\n';
    }   // end of while

    return 0;
}