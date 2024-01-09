#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string to_lower(string s) {
    string res;
    for(char c : s) {
        res += tolower(c);
    }
    return res;
}

string solution(string my_string) {
    string answer = to_lower(my_string);
    sort(answer.begin(), answer.end());
    return answer;
}