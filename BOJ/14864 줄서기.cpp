#include<iostream>
#include<vector>

using namespace std;

int N, M, x, y;
bool is_dup;
int a[1000004], visited[1000004];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        a[x]++;
        a[y]--;
    }   // end of for M

    for(int i = 1; i <= N; i++) {
        a[i] += i;
        visited[a[i]]++;

        if(visited[a[i]] >= 2) is_dup = true;
    }

    if(is_dup) {
        cout << -1 << '\n';
        return 0;
    }

    for(int i = 1; i <= N; i++) {
        cout << a[i] << ' ';
    }

    cout << '\n';
    return 0;
}