#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<char, int> m;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    // 미리 맵에 키 별로 최솟값 저장해놓기
    for(string s : keymap) {
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(m.find(c) == m.end()) m[c] = i + 1;
            else m[c] = min(m[c], i + 1);
        }   // end of for i
    }   // end of for keymap

    for(string s : targets) {
        int sum = 0;
        for(char c : s) {   // 입력이 불가능한 경우
            if(m.find(c) == m.end()) {
                sum = -1;
                break;
            }
            sum += m[c];
        }   // end of for s
        answer.push_back(sum);
    }   // end of for targets
    return answer;
}