#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[801];
int d[801];
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
	int n, e;
	scanf("%d %d", &n, &e);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	fill(d, d + 801, INF);
	dijkstra(1);
	int v1, v2;
	scanf("%d %d", &v1, &v2);
	if (d[v1] == INF && d[v2] == INF) {
		printf("-1\n");
		return 0;
	}
	int distv1 = d[v1], distv2 = d[v2];
	fill(d, d + 801, INF);		//배열 초기화 계속 해줘야됨. 시작 지점이 달라진거 고려할것
	dijkstra(v1);
	if (d[v2] == INF && d[n] == INF) {
		printf("-1\n");
		return 0;
	}
	distv1 += d[v2];	//	1 -> v1 -> v2 -> n	v2까지 저장
	distv2 += d[n];		// 1 -> v2 -> v1 -> n	v1 -> n 부터 일단 저장
	if (d[v2] == INF && d[n] == INF) {
		printf("-1\n");
		return 0;
	}
	fill(d, d + 801, INF);
	dijkstra(v2);
	distv1 += d[n];
	distv2 += d[v1];
	
	printf("%d\n", min(distv1, distv2));
}