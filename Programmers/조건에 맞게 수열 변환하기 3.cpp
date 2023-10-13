#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    for(int x : arr) {
        if(k % 2) {
            answer.push_back(x * k);
        } else {
            answer.push_back(x + k);
        }
    }

    return answer;
}