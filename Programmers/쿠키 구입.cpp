#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;

    for(int i = 0; i < cookie.size() - 1; i++) {
        int left_sum = cookie[i];
        int right_sum = cookie[i + 1];
        int lo = i;
        int hi = i + 1;

        while(1) {
            if(left_sum == right_sum) answer = max(answer, left_sum);

            if(left_sum < right_sum) {
                if(lo == 0) break;
                left_sum += cookie[--lo];
            } else {
                if(hi == cookie.size() -1) break;
                right_sum += cookie[++hi];
            }
        }   // end of while
    }   // end of for
    return answer;
}