#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> v(emergency.begin(), emergency.end());
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < emergency.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(emergency[i] == v[j]) {
                answer.push_back(j + 1);
                break;
            }
        }
    }

    return answer;
}