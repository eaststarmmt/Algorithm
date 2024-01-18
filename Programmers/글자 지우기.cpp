#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    sort(indices.begin(), indices.end());

    for(int i = 0, j = 0; i < my_string.size(); i++) {
        if(j == indices.size()) {
            answer += my_string.substr(i);
            break;
        }
        if(i == indices[j]) {
            j++;
            continue;
        }
        answer += my_string[i];
    }
    return answer;
}