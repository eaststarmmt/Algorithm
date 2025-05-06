#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 4004
#define INF 1e9
using namespace std;

int N, M, output, a, b, c;
int d_fox[MAX], d_wolf[MAX][2]; // 늑대는 0일때 2배속, 1일때 절반 속도
vector<pair<int, int>> graph[MAX];

void dijkstra_fox() {
    fill(d_fox, d_fox + MAX, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    d_fox[1] = 0;

    while(!pq.empty()) {
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();

        if(d_fox[here] != here_dist) continue;

        for(pair<int, int> p : graph[here]) {
            int there = p.second;
            int dist = p.first;

            if(dist + d_fox[here] >= d_fox[there]) continue;

            d_fox[there] = dist + d_fox[here];
            pq.push({d_fox[there], there});
        }   // end of for
    }   // end of while
}

void dijkstra_wolf() {
    fill(&d_wolf[0][0], &d_wolf[0][0] + MAX * 2, INF);
    priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<>> pq;
    d_wolf[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        int here_dist;
        int here;
        int flag;
        tie(here_dist, here, flag) = pq.top();
        pq.pop();

        if(here_dist != d_wolf[here][flag]) continue;

        for (pair<int, int> p: graph[here]) {
            int there = p.second;
            int dist = p.first;

            // 늑대 뛰는지 걷는지
            if(!flag) dist /= 2;
            else dist *= 2;

            if(dist + d_wolf[here][flag] >= d_wolf[there][!flag]) continue;

            d_wolf[there][!flag] = dist + d_wolf[here][flag];
            pq.push({d_wolf[there][!flag], there, !flag});
        }   // end of for
    }   // end of while

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        c *= 2;     // 절반 속도로 가는 연산을 쉽게 하기 위함
        // 양방향 그래프
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }   // end of for

    dijkstra_fox();
    dijkstra_wolf();

    for(int i = 1; i <= N; i++) {
        if(d_fox[i] >= d_wolf[i][0] || d_fox[i] >= d_wolf[i][1]) continue;
        output++;
    }
    cout << output << '\n';
}