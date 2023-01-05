#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;     // 지금까지 받은 콜라 수
    int bot = n;    // 빈 병 개수
    int coke = 0;
    while(bot >= a) {
        coke = (bot / a) * b;
        bot = (bot % a) + coke;
        answer += coke;
    }   // end of while
    return answer;
}