#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    sort(array.begin(), array.end());

    answer = array[0];

    for(int i = 1, idx = 0; i < array.size(); i++) {
        if(abs(n - array[i]) < abs(n - array[idx])) {
            answer = array[i];
            idx = i;
        }
    }
    return answer;
}