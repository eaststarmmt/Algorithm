#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 1e9
#define MAX 1004
using namespace std;

int N, M, X, s, e, c, output;
int d1[MAX], d2[MAX];
vector<pair<int, int>> graph[MAX], graph2[MAX];

void dijkstra(int *d, vector<pair<int, int>>* adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(d, d + N + 1, INF);
    d[X] = 0;
    pq.push({0, X});

    while (!pq.empty()) {
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();

        if(here_dist != d[here]) continue;

        for (pair<int, int> p: adj[here]) {
            int there = p.second;
            int dist = p.first;

            if(d[here] + dist >= d[there]) continue;

            d[there] = d[here] + dist;
            pq.push({d[there], there});
        }   // end of for
    }   // end of while
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;

    for(int i = 0; i < M; i++) {
        cin >> s >> e >> c;
        graph[s].push_back({c, e});
        graph2[e].push_back({c, s});    // 간선을 반대로 하면 돌아가는 위치를 같은 방법으로 구할 수 있음
    }   // end of for

    // 시작점을 X로 잡으면 돌아가는 길을 구하는 로직이 됨. X -> A, X -> B
    dijkstra(d1, graph);
    // 간선이 거꾸로 되어 있어서 시작점을 X로 잡으면 X까지 가는 시간이 됨. A -> X, B -> X
    dijkstra(d2, graph2);

    for(int i = 1; i <= N; i++) {
        output = max(output, d1[i] + d2[i]);
    }

    cout << output << '\n';
}