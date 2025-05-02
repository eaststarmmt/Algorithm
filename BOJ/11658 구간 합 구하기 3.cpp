#include<iostream>
#include<algorithm>
#define SIZE 1030
using namespace std;

int a[SIZE][SIZE], tree[SIZE][SIZE];
int N, M, w, r1, c1, r2, c2, x;

void update(int r, int c, int value) {
    int idx_r = r;

    while(idx_r <= N) {
        int idx_c = c;

        while(idx_c <= N) {
            tree[idx_r][idx_c] += value;
            idx_c += (idx_c & -idx_c);
        }   // end of while c

        idx_r += (idx_r & -idx_r);
    }   // end of while r
}

int sum(int r, int c) {
    int res = 0;
    int idx_r = r;

    while(idx_r > 0) {
        int idx_c = c;
        while(idx_c > 0) {
            res += tree[idx_r][idx_c];
            idx_c -= (idx_c & -idx_c);
        }   // end of while c

        idx_r -= (idx_r & -idx_r);
    }   // end of while r

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> a[i][j];
            update(i, j, a[i][j]);
        }   // end of for j
    }   // end of for i

    for(int i = 0; i < M; i++) {
        cin >> w;
        if(!w) {
            cin >> r1 >> c1 >> x;
            update(r1, c1, x - a[r1][c1]);
            a[r1][c1] = x;
        } else {
            cin >> r1 >> c1 >> r2 >> c2;
            cout << sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1) << '\n';
        }
    }   // end of for M

    return 0;
}