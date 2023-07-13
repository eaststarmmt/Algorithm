#include<iostream>

using namespace std;

double a[10004];
double res;

int main() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%lf", &a[i]);
    }   // end of for

    double mul = a[0];

    for(int i = 1; i < N; i++) {
        if (mul * a[i] > a[i]) {    // 곱했을 때 현재 바라보고 있는 값 보다 클 때만 곱하기
            mul *= a[i];
        } else {        // 더 커지지 않으면 그냥 다음 숫자부터 다시 시작
            mul = a[i];
        }

        res = max(res, mul);

    }

    printf("%.3lf\n", res);
    return 0;
}