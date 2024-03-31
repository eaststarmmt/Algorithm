#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;
int x, dp[5][5][100001];    // 왼발 오른발 인덱스

int get_score(int from, int to) {
    if(from == to) return 1;    // 같은 위치 누르는 경우
    else if(from == 0) return 2;    // 중앙에서 옮기는 경우
    else if(abs(from - to) == 2) return 4;   // 반대편에 있는 경우
    return 3;  // 인접위치로 옮기는 경우
}

int go(int left, int right, int here) {
    // 끝까지 다 한 경우 종료
    if(here == v.size()) return 0;

    int &res = dp[left][right][here];
    if(res) return res;

    int l = go(v[here], right, here + 1) + get_score(left, v[here]);
    int r = go(left, v[here], here + 1) + get_score(right, v[here]);

    return res = min(l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        cin >> x;
        if(!x) break;
        v.push_back(x);
    }   // end of while

    cout << go(0, 0, 0) << '\n';
}