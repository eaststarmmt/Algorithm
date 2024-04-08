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
    // string은 첫 글자를 먼저 비교해서 123이 23보다 작다고 판단함
    if(a.size() == b.size()) return (a < b ? a : b);    // 길이 같으면 그대로 작은 값 리턴
    return (a.size() < b.size() ? a : b);   // 크기 작은게 작은값
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    fill(&dp[0], &dp[103], MAX);

    dp[0] = "";

    // bottom up
    for(int i = 2; i < 104; i++) {  // 성냥 갯수
        for(int j = 0; j <= 9; j++) {   // 만들 숫자
            if(i - a[j] < 0) continue;  // 성냥 모자란 경우
            if(j == 0 && dp[i - a[j]] == "") continue;  // 첫 글자로 0이 올 수 없음
            // 기존 값과 a[j]가 들어오기 전의 갯수 + a[j] 만드는데 필요한 갯수 비교하여 최솟값 저장
            dp[i] = get_min(dp[i], dp[i - a[j]] + to_string(j));
        }
    }   // end of for i

    while(T--) {
        cin >> N;
        cout << dp[N] << ' ' << get_max(N) << '\n';
    }   // end of while

    return 0;
}