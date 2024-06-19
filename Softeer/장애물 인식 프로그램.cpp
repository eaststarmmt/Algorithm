#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> res;
int N;
int a[30][30], visited[30][30];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int dfs(int r, int c) {
    int res = 1;
    visited[r][c] = 1;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        // validation check
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(visited[nr][nc]) continue;
        if(!a[nr][nc]) continue;

        res += dfs(nr, nc);
    }  // end of for

    return res;
}

int main(int argc, char** argv)
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%1d", &a[i][j]);
        }  // end of for j
    }  // end of for i

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j] || !a[i][j]) continue;
            res.push_back(dfs(i, j));
        }  // end of for j
    }  // end of for i

    sort(res.begin(), res.end());

    cout << res.size() << '\n';

    for(int x : res) {
        cout << x << '\n';
    }  // end of for res

    return 0;
}