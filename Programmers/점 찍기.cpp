#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    // x값을 k배수로 증가시키면서 가능한 y 값 찾기
    for(long long x = 0; x <= d; x += k) {
        // 피타고라스 정리
        long long yy = (long long)d * d - x * x;
        // 0인 경우가 있어서 +1 해줘야 됨
        answer += (long long)sqrt(yy) / k + 1;
    }
    return answer;
}