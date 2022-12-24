#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int idx;
bool cmp(string& a, string& b) {
    if(a[idx] == b[idx]) {
        return a < b;
    }
    return a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(), strings.end(), cmp);
    vector<string> answer = strings;
    return answer;
}