#include <iostream>
using namespace std;

long long a[104];
long long dp[104][24];  // idx, sum값. 현재까지 인덱스에 왔을때 sum값에 대한 메모이제이션을 걸어서 중복 연산 방지
int N;

long long go(int idx, long long sum) {
    if(sum < 0 || sum > 20) return 0;   // 음수와 20이 넘는 수는 모르기 때문에 연산 되지 않게 걸러주기

    long long &res = dp[idx][sum];
    if(res) return res;     // 저장된 값이 있으면 그 값 사용하기

    if(idx == N - 2) {
        if(sum == a[N - 1]) return res = 1;   // 원하는 값이 나왔으면 1을 리턴하여 더해주기
        return 0;   // 원하는 값이 나오지 않은 경우 0을 리턴하여 카운팅 되지 않게 걸러주기
    }

    res += go(idx + 1, sum + a[idx + 1]);
    res += go(idx + 1, sum - a[idx + 1]);

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }   // end of for

    cout << go(0, a[0]) << '\n';
    return 0;

}