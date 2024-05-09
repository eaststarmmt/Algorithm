#include<iostream>
using namespace std;

int N, ldr, mbr;
int cust[1000004];
long long res;

long long counting(int x) { // 가게 별 필요 인원 계산 함수
    long long cnt = 1;  // 팀장 한 명은 기본으로 가져가야 되기 때문에 1로 초기화
    int cu = x - ldr;   // 가게에 있는 고객 수 - 팀장이 담당할 고객 수

    if(cu <= 0) return cnt;  // 팀장이 혼자 감당 가능하면 종료

    cnt += cu / mbr;
    return cu % mbr == 0 ? cnt : cnt + 1;   // 나머지가 있으면 남는 고객이 있다는 의미이므로 한명 더 붙여야 됨

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> cust[i];
    }   // end of for

    cin >> ldr >> mbr;

    for(int i = 0; i < N; i++) {
        res += counting(cust[i]);
    }   // end of for

    cout << res << "\n";
}