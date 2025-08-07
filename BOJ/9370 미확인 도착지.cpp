#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define INF 1e9
using namespace std;

int test, N, M, T, S, G, H, a, b, d, x;
int dist[2004];

void dijkstra(vector<pair<int, int>> (&graph)[2004], vector<int>& dest) {
    fill(dist, dist + N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, S});
    dist[S] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        if(dist[cur] != dis) continue;
        for(pair<int, int> p : graph[cur]) {
            int next = p.second;
            int cost = p.first;
            if(dist[next] <= dist[cur] + cost) continue;
            dist[next] = dist[cur] + cost;
            pq.push({dist[next], next});
        }   // end of for
    }   // end of while

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> test;

    while (test--) {
        cin >> N >> M >> T >> S >> G >> H;
        vector<pair<int, int>> graph[2004];     // 인접행렬
        vector<int> dest;       // 목적지

        for(int i = 0; i < M; i++) {
            cin >> a >> b >> d;
            d *= 2;
            if(a == G && b == H) d--;
            if(a == H && b == G) d--;
            graph[a].push_back({d, b});
            graph[b].push_back({d, a});
        }   // end of for graph

        for(int i = 0; i < T; i++) {
            cin >> x;
            dest.push_back(x);  // g와 h 차이를 지났는지 확인하기 위해 모두 짝수로 만듬
        }   // end of for dest

        sort(dest.begin(), dest.end());
        dijkstra(graph, dest);

        for(int pos : dest) {
            if(dist[pos] & 1) cout << pos << ' ';
        }
        cout << '\n';
    }   // end of while
}