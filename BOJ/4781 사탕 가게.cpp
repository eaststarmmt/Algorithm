#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, m1, m2, dp[10004], c, p;

int main() {
    while(1) {
        scanf("%d %d.%d", &N, &m1, &m2);     // 실수형 연산을 정수형으로 바꾸기 위한 방법
        M = m1 * 100 + m2;

        // 초기화
        fill(dp, dp + M + 1, 0);

        if(N == 0) break;   // 입력 마지막 줄인 경우 0 입력

        for(int i = 0; i < N; i++) {
            scanf("%d %d.%d", &c, &m1, &m2);
            p = m1 * 100 + m2;

            for(int j = p; j <= M; j++) {
                dp[j] = max(dp[j], dp[j - p] + c);
            }   // end of for j
        }   // end of for i

        printf("%d\n", dp[M]);
    }   // end of while

    return 0;
}