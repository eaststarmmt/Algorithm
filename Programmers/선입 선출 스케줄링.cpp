#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 1e9
using namespace std;

long long get_sum(int time, vector<int>& cores) {
    long long sum = 0;

    for(int x : cores) {
        sum += time / x + 1;     // 코어 당 작업한 일의 개수
    }   // end of for

    return sum;
}

bool check(long long mid, int n, vector<int>& cores) {
    long long sum = get_sum(mid, cores);

    return sum < n;     // 모두 처리하기 1시간 전에 값을 구하는게 목적이므로 등호 안붙임
}

long long binary(int n, vector<int>& cores) {
    long long res = -1;
    long long left = 0;
    long long right = INF;

    while(left <= right) {
        long long mid = (left + right) / 2;
        if(check(mid, n, cores)) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }   // end of while

    return res;
}

int solution(int n, vector<int> cores) {
    int answer = 0;
    if(n <= cores.size()) return n;

    long long time = binary(n, cores);  // 일 하는데 걸린 시간을 구하기 위함.
    int remain = n - get_sum(time, cores);  // 전체 작업 - 끝나기 한시간 전 작업
    time++;     // 마지막 시간때 누가 작업하는 구하기 위해 +1을 해줌

    // 마지막 한시간 누가 작업하게 되는지 찾기
    for(int i = 0; i < cores.size(); i++) {
        if(time % cores[i]) continue;    // 다른 작업을 들고 있으면 무시
        remain--;
        if(!remain) {   // 마지막 작업인 경우 번호 표시 후 반복문 제거
            answer = i + 1;
            break;
        }
    }   // end of for

    return answer;
}