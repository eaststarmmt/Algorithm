#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.size(); i++) {
        if(!isalpha(s[i])) continue;
        if((isupper(s[i]) && isupper(s[i] + n)) || 
           (islower(s[i]) && islower(s[i] + n))) s[i] += n;
        else s[i] += n - 26;
        
    }
    answer = s;
    return answer;
}