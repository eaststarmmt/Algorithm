#include <string>
#include <vector>

using namespace std;

string to_upper(string s) {
    string upper = "";
    for(char c : s) {
        upper += toupper(c);
    }
    return upper;
}

string solution(string my_string, string alp) {
    string answer = my_string;
    int idx = answer.find(alp);     // alp가 있다면 시작하는 인덱스 찾기
    
    // alp가 하나도 없을때까지 계속 변환
    while(idx != string::npos) {
        answer.replace(idx, alp.size(), to_upper(alp));
        idx = answer.find(alp);
    }
    return answer;
}