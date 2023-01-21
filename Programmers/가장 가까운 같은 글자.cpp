#include <string>
#include <vector>

using namespace std;

int check[30];

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];  // 현재 문자
        
        // 나온적 있으면 현 인덱스와 차이. 나온적 없으면 -1
        check[c - 'a']? answer.push_back(i - check[c - 'a'] + 1): answer.push_back(-1); 
        // 현재 알파벳 위치를 저장하여 최근 인덱스 위치 기록하기
        // i + 1을 하지 않으면 처음에 나온 알파벳이 0으로 기록 되어 안나온 문자와 구분이 되지 않음
        check[c - 'a'] = i + 1; 
    }   // end of for
    
    return answer;
}   