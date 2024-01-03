#include <string>
#include <vector>
#include <queue>
using namespace std;

// 무적권 사용했을때 x 처리 되는지 확인
void mujuckwon(priority_queue<int>& pq, int& n, int& x, int& k) {
    k--;
    if(pq.empty() || pq.top() <= x) { // x가 지금까지 나온 가장 큰 값이면 여기다 무적권 사용
        return;
    }
    // 더 큰 값이 나온적 있으면 제일 큰 값 빼고 그걸로 x 해결
    n += pq.top() - x;
    pq.pop();
    pq.push(x);
}

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq; // 지금까지 나온 병력의 최대값 저장하기 위함

    for(int x : enemy) {
        if(x <= n) {    // 남은 병력으로 처리 가능한 경우
            n -= x;
            pq.push(x);
        } else if(!k) { // 여기서부터 현상태로 처리 불가능한 경우. 무적권 없으면 불가능
            break;   // 무적권 없으면 해결 불가능
        } else {
            mujuckwon(pq, n, x, k);
        }
        answer++;   // 반복문이 종료되지 않았으면 디펜스 성공
    }
    return answer;
}