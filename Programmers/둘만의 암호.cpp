#include <string>
#include <vector>

using namespace std;

int a[30];

string solution(string s, string skip, int index) {
    string answer = "";

    for(char c : skip) {
        a[c - 'a']++;
    }   // end of for skip

    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        for(int j = 0; j < index; j++) {
            while(true) {
                c = c + 1 > 'z' ? 'a' + c - 'z' : c + 1;
                if(!a[c - 'a']) break;
            }
        }
        answer += c;
    }   // end of for s
    return answer;
}