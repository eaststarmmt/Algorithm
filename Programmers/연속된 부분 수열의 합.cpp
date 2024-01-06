#include <string>
#include <vector>
#define INF (int)1e9
using namespace std;

int lo, hi;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {-INF, INF};
    int sum = sequence[0];

    while(true) {
        if(sum <= k) {   // k 보다 크거나 작은 경우
            if(sum == k) {
                int answer_dif = answer[1] - answer[0];
                int cur_dif = hi - lo;
                // 길이 더 짧은 경우 갱신
                if(cur_dif < answer_dif) {
                    answer[0] = lo;
                    answer[1] = hi;
                }
            }
            hi++;   // 다음 원소 더하기
            if(hi >= sequence.size()) break;    // 수열을 끝까지 본 경우
            // 같은 경우
            sum += sequence[hi];
        } else {    // k 보다 큰 경우
            sum -= sequence[lo];
            lo++;
        }
    }   // end of while

    return answer;
}