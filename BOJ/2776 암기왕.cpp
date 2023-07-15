#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int T, N, M;

int find_num(vector<int>& v, int x) {
    int lo = 0;
    int hi = v.size() - 1;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;

        if(v[mid] > x) {
            hi = mid - 1;
        } else if(v[mid] < x) {
            lo = mid + 1;
        } else {
            return 1;
        }
    }	// end of while

    return 0;
}

void solve() {
    scanf("%d", &N);
    vector<int> v;

    for(int i = 0; i < N; i++) {	// 수첩1에 저장
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }	// end of for i

    sort(v.begin(), v.end());

    scanf("%d", &M);

    for(int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        cout << find_num(v, x) << "\n";
    }
}

int main() {

    scanf("%d", &T);
    for(int test = 0; test < T; test++) {
        solve();
    }	// end of for test

    return 0;
}