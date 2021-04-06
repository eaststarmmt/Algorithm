#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;
vector<pair<int, int>> graph[20001];	//크기는 노드 갯수 기준으로 잡기
int d[20001];
// 생각이 있으면 외울것. 언제 물어봐도 숨도 안쉬고 손가락이 움직여야됨
void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist > d[now]) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ cost, graph[now][i].first });
			}
		}
	}
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({ v, w });
	}
	fill(d, d + 20001, INF);
	dijkstra(k);
	for (int i = 1; i <= n; i++) {
		if (d[i] == INF) printf("INF\n");
		else printf("%d\n", d[i]);
	}
}