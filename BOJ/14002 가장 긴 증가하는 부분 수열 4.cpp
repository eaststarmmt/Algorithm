#include<iostream>
#include<algorithm>
using namespace std;

int N, idx, res = 1;    // res 1로 초기화 안하면 N이 1일 때 0이 출력 됨
int a[1004], dp[1004], prev_idx[1004];

void print(int idx) {
    if(idx == -1) {
        return;
    }

    print(prev_idx[idx]);
    cout << a[idx] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    fill(prev_idx, prev_idx + N, -1);

    for(int i = 0; i < N; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i] && dp[j] + 1 > dp[i]) {      // j번째보다 크면 일단 j + 1개의 부분 증가 수열 완성. 길이는 j번째 + 1을 한게 i 값이 됨
                dp[i] = dp[j] + 1;
                prev_idx[i] = j;
                if(res < dp[i]) {   // 최댓값 나온 마지막 인덱스 기억하기
                    idx = i;    // 마지막으로 LIS가 저장된 인덱스 위치 확인
                    res = dp[i];
                }
            }
        }   // end of for j
    }   // end of for i
    cout << res << "\n";
    print(idx);

    return 0;
}

