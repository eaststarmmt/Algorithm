#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define INF 1e9
using namespace std;

int N, M, S, D, u, v, p, output;
int d[504];
int graph[504][504];    // 이 문제에서는 최단경로를 지워야 해서 벡터보다는 배열이 더 편함

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(d, d + 504, INF);
    d[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();

        if(here_dist != d[here]) continue;

        for(int there = 0; there < N; there++) {
            if(graph[here][there] == -1) continue;  // 못가는 곳 체크한 경우 무시
            int dist = graph[here][there];

            if(d[here] + dist >= d[there]) continue;    // 더 크면 할 필요 없음

            d[there] = d[here] + dist;
            pq.push({d[there], there});
        }   // end of for there
    }   // end of while
}

void erase_edge() {
    queue<int> Q;
    Q.push(D);

    while (!Q.empty()) {    // 끝지점부터 최단경로 여부 확인
        int here = Q.front();
        Q.pop();

        for(int i = 0; i < N; i++) {
            // 시작부터 here까지 경로 = i에서 here까지 거리 + 시작부터 i까지 거리가 같으면 최단경로
            // -1 체크가 안된 부분만 확인하지 않으면 중복으로 계속 돌게 됨
            if(d[here] == d[i] + graph[i][here] && graph[i][here] != -1) {
                graph[i][here] = -1;
                Q.push(i);
            }
        }   // end of for
    }   // end of while
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        cin >> N >> M;
        if(!N && !M) break;

        cin >> S >> D;

        memset(graph, -1, sizeof(graph));   // 없는 edge와 지운 edge 표시하기 위함

        for(int i = 0; i < M; i++) {
            cin >> u >> v >> p;
            graph[u][v] = p;
        }   // end of for

        dijkstra();
        erase_edge();
        dijkstra();

        output = d[D] == INF ? -1 : d[D];
        cout << output << '\n';
    }   // end of while
}