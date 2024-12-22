#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

char a[] = {'(', ')', '{', '}', '[', ']'};
string dp[1004];
map<char, char> mp;
int T, N;

bool check(string before, string after) {
    if(before == "" && after == "") return false;
    if(before == "") return true;
    if(before.size() == after.size()) return after < before;    // dmap의 값이 최소가 되야 하므로 길이가 같으면 앞에 작은 숫자가 와야 됨
    return after.size() < before.size();    // after가 작은 경우가 true가 되어야 밖에서 수정함
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 6; i++) {
        mp[i + '1'] = a[i];     // 괄호를 숫자로 바꿔줌
    }   // end of for

    // 1 2 3 의 최솟값 저장
    dp[1] = "12";   // ()
    dp[2] = "34";   // {}
    dp[3] = "56";   // []

    for(int val = 1; val <= 1000; val++) {
        // 곱셈연산으로 작아지는 경우 체크.
        if(val % 2 == 0 && check(dp[val], '1' + dp[val / 2] + '2')) dp[val] = '1' + dp[val / 2] + '2';
        if(val % 3 == 0 && check(dp[val], '3' + dp[val / 3] + '4')) dp[val] = '3' + dp[val / 3] + '4';
        if(val % 5 == 0 && check(dp[val], '5' + dp[val / 5] + '6')) dp[val] = '5' + dp[val / 5] + '6';

        for(int i = 1; i <= val; i++) {     // 덧셈연산으로 작아지는 경우 체크
            if(check(dp[val], dp[i] + dp[val - i])) dp[val] = dp[i] + dp[val - i];
        }
    }

    cin >> T;

    while(T--) {
        cin >> N;
        for(char c : dp[N]) cout << mp[c];
        cout << '\n';
    }   // end of while

    return 0;
}