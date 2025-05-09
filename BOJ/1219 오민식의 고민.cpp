#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define ll long long
#define INF 1e18
using namespace std;

int N, M, S, E, t1, t2, t3;
int visited[104];
vector<pair<int, int>> graph[104];
ll d[104], cost[104];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S >> E >> M;
    fill(d, d + 104, -INF);

    for(int i = 0; i < M; i++) {
        cin >> t1 >> t2 >> t3;
        graph[t1].push_back({t2, t3});
    }

    for(int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    d[S] = cost[S];
    queue<int> Q;
    for(int i = 0; i < N; i++) {
        for(int here = 0; here < N; here++) {
            for (pair<int, int> p: graph[here]) {
                int there = p.first;
                int dist = p.second;

                if(d[here] != -INF && d[here] - dist + cost[there] > d[there]) {    // 완화. 기존값보다 커지기 때문에 음의 사이클은 아님
                    d[there] = d[here] - dist + cost[there];
                    if(i == N - 1) Q.push(there);
                }
            }   // end of for graph
        }   // end of for here
    }   // end of for N

    bool flag = false;  // 방문 가능 여부 체크용 플래그
    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();

        if(x == E) {
            flag = true;    // 여기서 표시 안하면 싸이클이 있는건지 없는데 온건지 모름
            break;
        }

        for (pair<int, int> p: graph[x]) {
            int next = p.first;
            if(visited[next]) continue;
            visited[next] = true;
            Q.push(next);
        }   // end of for
    }   // end of while

    if(d[E] == -INF) cout << "gg";
    else if(flag) cout << "Gee";
    else cout << d[E];

    cout << '\n';
}