#include <string>
#include <vector>

using namespace std;

int dp[18][18];     // 열어야 되는 괄호 수, 닫아야 되는 괄호 수

int memoization(int open, int close) {
    // 종료 조건 & 방어로직
    if(open < 0 || close < 0) return 0;
    if(open == 0 && close == 0) return 1;

    // 메모이제이션
    int &res = dp[open][close];

    if(res) return res;

    if(open > 0) {
        res += memoization(open - 1, close + 1);    // 열었으니 닫을게 하나 생김
    }

    if(close > 0) {
        res += memoization(open, close - 1);
    }

    return res;
}

int solution(int n) {
    int answer = memoization(n, 0);
    return answer;
}