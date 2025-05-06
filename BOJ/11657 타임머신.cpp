#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAX 504
#define INF 1e9
using namespace std;

long long  N, M, a, b, c;
vector<pair<int, int>> graph[MAX];
long long d[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }   // end of for

    fill(d, d + MAX, INF);
    d[1] = 0;
    queue<int> Q;

    for(int i = 1; i <= N; i++) {
        for(int here = 1; here <= N; here++) {
            for(pair<int, int> p : graph[here]) {
                int there = p.first;
                int dist = p.second;

                if(d[here] != INF && d[here] + dist < d[there]) {  // here까지 가는게 무한대가 아니고 완화가 되는 경우
                    d[there] = dist + d[here];  // 완화
                    if(i == N) Q.push(there);   // N번째 반복하는데 아직도 완화가 된되면 음의 사이클이 있음
                }
            }   // end of for graph
        }   // end of for here
    }   // end of for N

    if(Q.size()) cout << -1 << '\n';
    else {
        for(int i = 2; i <= N; i++) {
            cout << (d[i] == INF ? -1 : d[i]) << '\n';
        }
    }
}