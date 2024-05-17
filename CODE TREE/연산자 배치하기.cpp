#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, a[16], oper[5];
int _min = INF;
int _max = -INF;

void go(int num, int cnt, int plus, int minus, int mul) {
    if(cnt == N - 1) {  // 연산 끝까지 진행한 경우
        _min = min(_min, num);
        _max = max(_max, num);
        return;
    }

    if(plus) go(num + a[cnt + 1], cnt + 1, plus - 1, minus, mul);
    if(minus) go(num - a[cnt + 1], cnt + 1, plus, minus - 1, mul);
    if(mul) go(num * a[cnt + 1], cnt + 1, plus, minus, mul - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }   // end of for num

    for(int i = 0; i < 3; i++) {
        cin >> oper[i];
    }   // end of for oper

    go(a[0], 0, oper[0], oper[1], oper[2]);

    cout << _min << ' ' << _max << "\n";
    return 0;
}