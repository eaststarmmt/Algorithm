#include<iostream>
#define INF 60000000004

using namespace std;

long long N, M, res, a[10004];

bool check(long long mid) {
    long long sum = M;

    for(int i = 0; i < M; i++) {
        sum += mid / a[i];
    }	// end of for

    return sum >= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a[i];
    }	// end of for

    if(N <= M) {	// 아이들이 놀이기구보다 적으면 N 값이 답
        cout << N << "\n";
        return 0;
    }

    long long lo = 0;
    long long hi = INF;

    while(lo <= hi) {
        long long mid = (lo + hi) / 2;

        if(check(mid)) {	// 아이들이 다 탈수 있는 시간중에 가장 작은 시간을 구해야 됨
            hi = mid - 1;
            res = mid;
        } else {
            lo = mid + 1;
        }
    }	// end of while

    long long sum = M;

    for(int i = 0; i < M; i++) {	// 아이들이 탈 수 있는 시간 바로 전 시간에 몇번까지 탔는지 체크
        sum += ((res - 1) / a[i]);	// 1을 빼서 아이들이 다 탈수 있는 시간 바로 전 시간으로 줄이기
    }	// end of for

    for(int i = 0; i < M; i++) {
        if(res % a[i] == 0) sum++;	// 해당 시간때 놀이기구 비면 카운팅
        if(sum == N) {
            cout << i + 1 << "\n";	// i가 0부터 시작하므로 +1 해줘야 놀이기구 번호가 됨
            break;
        }
    }

    return 0;
}