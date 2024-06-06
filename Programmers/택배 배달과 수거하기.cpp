#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int delivery, pickup, delivery_idx, pickup_idx;

int get_dis(int cap, vector<int>& v, int& cnt, int& idx) {
    int max_dis = 0;
    for(int i = idx; i >= 0; i--) {
        if(!max_dis && v[i]) max_dis = i + 1;  // 가장 먼 거리 하나만 저장. 가장 멀리 있는 것 중 남은 집까지의 거리
        // 수거 or 배달 처리. SRP 위반이라 인덱스 찾는거랑 나누는게 맞긴 한데..... 좀 귀찮다.....
        int dif = min(cap, v[i]);   // 배달 or 수거 해야 되는 개수랑 트럭에 실은 짐 개수 중 적은 수 만큼
        v[i] -= dif;    // 트럭에서 가능한 택배 수 만큼 수거 or 배달 처리
        cnt -= dif;     // 남은량 카운팅
        cap -= dif;     // 택배에 남은 수량 카운팅
        idx = i;        // 마지막으로 조회한 인덱스 저장
        if(!cap) break; // 트럭 짐 칸 다 썼으면 종료
    }   // end of for v

    return max_dis;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    // 남은 배달 개수와 수거 개수 저장
    for(int i = 0; i < n; i++) {
        delivery += deliveries[i];
        pickup += pickups[i];
    }   // end of for deliveries

    delivery_idx = pickup_idx = n - 1;  // 배달과 수거 마지막 인덱스 체크용. TLE 막기 위해 탐색 범위 좁히기

    while(delivery || pickup) {     // 배달이나 수거가 하나라도 남았으면 반복
        // TLE 막기 위해 배달, 수거 남은게 있는 경우만 탐색
        int delivery_dis = delivery ? get_dis(cap, deliveries, delivery, delivery_idx) : 0;
        int pickup_dis = pickup ? get_dis(cap, pickups, pickup, pickup_idx) : 0;

        // 둘중에 먼 거리 만큼 증가함. 왕복이기 때문에 *2
        answer += max(delivery_dis, pickup_dis) * 2;
    }

    return answer;
}