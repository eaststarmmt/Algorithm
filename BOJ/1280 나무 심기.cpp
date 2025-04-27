#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 200004
#define ll long long
#define MOD (ll)(1e9 + 7)
using namespace std;

int N, pos;
ll output = 1;
vector<ll> tree_sum(MAX), tree_cnt(MAX);

ll sum(vector<ll>& tree, int pos) {
    ll res = 0;
    int idx = pos;
    while(idx) {
        res += tree[idx];
        idx -= (idx & -idx);    // sum은 마지막 비트를 하나씩 없애나가면서 탐색하는 방식
    }   // end of while
    return res;
}

void update(vector<ll>& tree, int pos, ll value) {
    int idx = pos;
    while(idx <= MAX) {
        tree[idx] += value;
        idx += (idx & -idx);    // update는 마지막 비트를 더해서 영향받는 다음 비트로 탐색하는 방식
    }   // end of while
}

ll get_sum(vector<ll>& tree, int start, int end) {
    if(start > end) return 0;   // 위치가 1인경우 end가 작을 수 있음
    return sum(tree, end) - sum(tree, start - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> pos;
        pos++;  // 0부터 시작인데 1부터 사용하기 위함
        if(i) {     // 처음 나무는 거리 계산을 하지 않기 때문
            // 비용을 계산하는 과정이 거리를 계산하는 것이기 때문에 현재 위치를 기준으로 누적 계산함.
            // 왼쪽은 현위치 * 왼쪽 나무 개수 - 나무의 위치의 합. (현위치 - 나무 위치)의 합이기 때문에
            ll left = get_sum(tree_cnt, 1, pos - 1) * pos - get_sum(tree_sum, 1, pos - 1);
            // 오른쪽은 나무위치의 합 - (현위치 * 오른쪽 나무 개수)
            ll right = get_sum(tree_sum, pos + 1, MAX) - get_sum(tree_cnt, pos + 1, MAX) * pos;
            output *= (left + right) % MOD;
            output %= MOD;
        }

        update(tree_cnt, pos, 1);
        update(tree_sum, pos, pos);
    }   // end of for

    cout << output << '\n';
    return 0;
}