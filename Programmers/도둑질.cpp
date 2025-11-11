#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[2][1000004];

int solution(vector<int> money) {
    int answer = 0;

    dp[0][0] = money[0];
    dp[0][1] = money[0];
    dp[1][1] = money[1];
    dp[1][2] = max(money[1], money[2]); // 1부터 시작하지만 1을 안고르고 2를 골라도 됨

    for(int i = 2; i < money.size() - 1; i++) {
        dp[0][i] = max(dp[0][i - 2] + money[i], dp[0][i - 1]);
    }   // end of for

    for(int i = 3; i < money.size(); i++) {
        dp[1][i] = max(dp[1][i - 2] + money[i], dp[1][i - 1]);
    }

    answer = max(dp[0][money.size() - 2], dp[1][money.size() - 1]);
    return answer;
}