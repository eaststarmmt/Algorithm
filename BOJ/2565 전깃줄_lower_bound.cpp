#include<iostream>
#include<algorithm>
using namespace std;

int N, a[504], lis[504], cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        a[x] = y;
    }   // end of for

    for(int i = 1; i <= 500; i++) {
        int num = a[i];
        if(num == 0) continue;  // 전깃줄 없으면 무시

        int idx = lower_bound(lis, lis + cnt, num) - lis;

        if(lis[idx] == 0) {
            cnt++;
        }
        lis[idx] = num;
    }

    cout << N - cnt << "\n";    // LIS만 남아야 되기 때문에 전체에서 LIS를 빼면 없앨 전깃줄 개수가 나옴

    return 0;
}

