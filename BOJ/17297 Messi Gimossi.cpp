#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int dp[100] = {0, 5, 13};
string s = "Messi Gimossi";
string blank = "Messi Messi Gimossi";
string output;
int M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    M--;    // string 인덱스로 판단하기 때문에 1 빼고 시작

    // 길이 저장
    for(int i = 3; i <= 40; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + 1;
    }   // end of for

    for(int i = 40; i >= 2; i--) {
        if(M >= dp[i]) M -= dp[i] + 1;  // 인덱스가 올라갈수록 공백이 추가 되어 1을 추가로 빼줘야 됨
    }   // end of for

    if(M == 5 || M == -1) output = blank;
    else output = s[M];
    cout << output << '\n';
}