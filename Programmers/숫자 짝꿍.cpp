#include <string>
#include <vector>

using namespace std;

int cnt1[10], cnt2[10];

void cnt(string s, int cnt[]) {
    for(char c : s) cnt[c - '0']++;
}

string solution(string X, string Y) {
    string answer = "";

    cnt(X, cnt1);
    cnt(Y, cnt2);

    for(int i = 9; i >= 0; i--) {
        int size = min(cnt1[i], cnt2[i]);
        if(answer.empty() && i == 0 && size) size = 1;
        for(int j = 0; j < size; j++) answer += (i + '0');
    }

    answer = answer.empty() ? "-1" : answer;
    return answer;
}