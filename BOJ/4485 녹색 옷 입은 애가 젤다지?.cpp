#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define INF 1e9
using namespace std;

int N, test;
int a[130][130], dist[130][130];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({a[0][0], 0});
    dist[0][0] = a[0][0];

    while (!pq.empty()) {
        int r = pq.top().second / 1000;
        int c = pq.top().second % 1000;
        int here_dist = pq.top().first;
        pq.pop();

        if(here_dist != dist[r][c]) continue;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

            int next_dist = here_dist + a[nr][nc];

            if (next_dist >= dist[nr][nc]) continue;

            dist[nr][nc] = next_dist;
            pq.push({next_dist, nr * 1000 + nc});
        }   // end of for

    }   // end of while

    return dist[N - 1][N - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(++test) {
        cin >> N;
        if(!N) break;

        memset(a, 0, sizeof(a));
        fill(&dist[0][0], &dist[0][0] + 130 * 130, INF);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> a[i][j];
            }   // end of for j
        }   // end of for i

        int res = dijkstra();
        cout << "Problem " << test << ": " << res << '\n';
    }   // end of while
}