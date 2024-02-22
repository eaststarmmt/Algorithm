#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[34];
int N, C, res;
vector<int> v1, v2;

void go(int here, int end, vector<int>& v, int sum) {
    if(sum > C) return;     // 더 이상 담을 수 없으면 종료
    if(here > end) {    // 끝까지 다 갔으면 담고 종료
        v.push_back(sum);
        return;
    }

    // 담는 경우와 담지 않는 경우 나눠서 완전탐색
    go(here + 1, end, v, sum + a[here]);
    go(here + 1, end, v, sum);

    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }   // end of for

    go(0, N / 2 - 1, v1, 0);
    go(N / 2, N - 1, v2, 0);

    // Meet in the middle. 중간에서 만나기
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // 배열을 각각 오름차순 했으니 한쪽 배열에서 다른쪽 배열의 합이 C를 넘지 않는 곳까지는 더해서 값을 만들 수 있음
    // upper_bound를 이용하면 인덱스가 0부터 시작하기 때문에 정확히 경우의 수와 일치
    for(int x : v1) {
        if(C >= x) {     // x가 무게 초과 하지 않은 경우
            // c - x 를 찾아야 C 와 합쳐서 가능한 갯수 카운팅이 정확하게 됨
            res += (int)(upper_bound(v2.begin(), v2.end(), C - x) - v2.begin());
        }
    }   // end of for

    cout << res << '\n';
}