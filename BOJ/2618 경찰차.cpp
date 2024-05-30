#include<cstdio>
#include<algorithm>

using namespace std;

int dp[1004][1004], pr[1004], pc[1004], N, W, r, c;

int get_dist(int x, int y) {
    return abs(pr[x] - pr[y]) + abs(pc[x] - pc[y]);
}

int go(int a, int b) {
    if(a > W || b > W) return 0;    // 범위 초과 시
    if(dp[a][b]) return dp[a][b];   // 값이 이미 있는 경우

    int next = max(a, b) + 1;

    return dp[a][b] = min(go(a, next) + get_dist(b, next), go(next, b) + get_dist(a, next));
}

void print() {
    int a = 0;
    int b = 1;

    for(int i = 2; i < W + 2; i++) {
        if(dp[a][i] + get_dist(i, b) < dp[i][b] + get_dist(i, a)) {
            puts("2");
            b = i;
        } else {
            puts("1");
            a = i;
        }
    }   // end of for
}

int main() {
    scanf("%d %d", &N, &W);
    pr[0] = pc[0] = 1;
    pr[1] = pc[1] = N;

    for(int i = 2; i < W + 2; i++) {
        scanf("%d %d", &r, &c);
        pr[i] = r;
        pc[i] = c;
    }   // end of for

    printf("%d\n", go(0, 1));
    print();
}