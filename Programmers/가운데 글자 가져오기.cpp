#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    int size = s.size();
    
    if(size % 2 == 1) {
        answer = s.substr(size / 2 , 1);
    } else {
        answer = s.substr(size / 2 - 1, 2);
    }
    return answer;
}