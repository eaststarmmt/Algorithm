#include<iostream>
#include<algorithm>
using namespace std;

int lis[1004], cnt, res, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        int idx = lower_bound(lis, lis + cnt, num) - lis;

        if(lis[idx] == 0) {     // 해당 lis 자리에 아직까지 값이 안들어왔으면 개수 카운팅
            cnt++;
        }
        lis[idx] = num;     // lis 배열에 값 저장

    }   // end of for

    cout << cnt << "\n";

    return 0;
}