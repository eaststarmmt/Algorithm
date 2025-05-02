#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

int N, M, K, t1, t2, t3;
ll t4;

void update(vector<ll>& tree, int idx, ll value) {
    int i = idx;
    while(i <= N) {
        tree[i] += value;
        i += (i & -i);
    }   // end of while
}

ll sum(vector<ll>& tree, int idx) {
    int i = idx;
    ll res = 0;

    while(i > 0) {
        res += tree[i];
        i -= (i & -i);
    }   // end of while
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    vector<ll> a(N + 1);    // 배열로 100만개를 담기는 힘들어서 vector로 할당
    vector<ll> tree(N + 1);

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        update(tree, i, a[i]);
    }   // end of for

    for(int i = 0; i < M + K; i++) {
        cin >> t1;
        if(t1 == 1) {
            cin >> t2 >> t4;
            update(tree, t2, t4 - a[t2]);   // 펜윅트리는 값을 변경하는게 불가능. 차이만큼 빼는 방법으로 해야 됨
            a[t2] = t4;
        } else {
            cin >> t2 >> t3;
            cout << sum(tree, t3) - sum(tree, t2 - 1) << '\n';
        }
    }   // end of for

    return 0;
}