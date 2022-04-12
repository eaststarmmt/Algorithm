#include<stdio.h>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;
vector<pair<int, int>> graph[1001]; // 첫번째 값 두번째 값 뭔지 확실히 하기. 크기는 노드 개수로 잡기
int d[1001];
// 그냥 다익스트라 외워놓고 푸는 문제
void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start }); // 여기서 첫번째 값이 거리인지 노드번호인지 잘 기억하기. 헷갈리면 존나 짜증남
	d[start] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;
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
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
	}
	int start, end;
	scanf("%d %d", &start, &end);
	fill(d, d + 1001, INF);
	dijkstra(start);
	printf("%d \n", d[end]);
}