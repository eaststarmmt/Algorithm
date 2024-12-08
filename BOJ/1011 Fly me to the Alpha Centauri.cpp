#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int T, res;
long long x, y, dis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--) {
        cin >> x >> y;
        dis = y - x;

        double sq = sqrt(dis);  // 거리의 제곱근
        long long rou = round(sq);      // 제곱근을 반올림 한 값

        res = sq > rou ? rou * 2 : rou * 2 - 1;     // 제곱근이 반올림보다 큰 경우와 아닌 경우로 나뉨
        cout << res << '\n';
    }   // end of while

    return 0;
}