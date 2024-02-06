#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[30];

string solution(string s) {
    string answer = "";
    for(char c : s) {
        cnt[c - 'a']++;
    }   // end of for

    for(char c = 'ala'; c <= 'z'; c++) {
        if(cnt[c - 'a'] == 1) answer += c;
    }   // end of for

    sort(answer.begin(), answer.end());

    return answer;
}