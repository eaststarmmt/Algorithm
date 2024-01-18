#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string myString, string pat) {
    string answer = myString;
    reverse(answer.begin(), answer.end());
    reverse(pat.begin(), pat.end());
    int end = answer.find(pat);

    answer = myString.substr(0, myString.size() - end);
    return answer;
}