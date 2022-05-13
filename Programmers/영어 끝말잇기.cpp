#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> map;
    int cnt = -1;
    for(int i = 0; i < words.size(); i++) {
        if(i != 0 && (words[i][0] != words[i - 1][words[i - 1].size() - 1])) {  // 끝말잇기 틀린경우
            cnt = i;
            break;
        }
        if(map.find(words[i]) == map.end()) {   // 단어 중복 안된경우. 즉 탈락 안한경우
            map[words[i]]++;
        } else {    // 탈락 한 경우
            cnt = i;
            break;
        }
    }   // end of for
    if(cnt == -1) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back((cnt % n) + 1);
        answer.push_back(cnt / n + 1);
    }
    return answer;
}