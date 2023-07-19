#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

double A, B;
int prime[20];
double dp[20][20][20];

void eratos() {
    fill(prime, prime + 20, 1);    // 1이 소수 0이 합성수
    prime[0] = 0;   // 0 과 1은 합성수는 아니지만 편의상 0으로 분류
    prime[1] = 0;
    for(int i = 2; i <= 10; i++) {
        if(!prime[i]) continue;      // 0이면 이미 배수들이 합성수로 분류가 끝나 있음
        for(int j = i * 2; j < 20; j += i) {
            prime[j] = 0;   // 합성수 0으로 분류
        }
    }
}

double dynamic(int cnt, int a, int b) {
    if(cnt == 18) {     // 탈출 조건
        return prime[a] || prime[b] ? 1.0 : 0.0;
    }

    double &res = dp[cnt][a][b];
    if(res > -0.1) return res;  // double 특성상 비교연산자로 비교가 힘듬.

    res = 0.0;

    res += dynamic(cnt + 1, a + 1, b) * A * (1 - B);
    res += dynamic(cnt + 1, a, b + 1) * (1 - A) * B;
    res += dynamic(cnt + 1, a + 1, b + 1) * A * B;
    res += dynamic(cnt + 1, a, b) * (1 - A) * (1 - B);

    return res;
}

int main() {
    scanf("%lf %lf", &A, &B);
    A /= 100;
    B /= 100;
    eratos();
    memset(dp, -1, sizeof(dp));
    printf("%.6lf\n", dynamic(0, 0, 0));
}