#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;

int cnt;
int d[100001];

void dijkstra(int start, vector<vector<pair<int, int>>> graph) {
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
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		int n, m, c;
		scanf("%d %d %d", &n, &m, &c);
		vector<vector<pair<int, int>>> graph(n + 1);	// 배열 형태로는 넘어가지 않아서 vector를 이중으로 크기를 지정해서 계속 초기화
		cnt = 0;

		for (int i = 0; i < m; i++) {
			int a, b, s;
			scanf("%d %d %d", &a, &b, &s);
			graph[b].push_back({ a, s });
		}

		fill(d, d + n + 1, INF);

		dijkstra(c, graph);

		sort(d, d + n + 1);
		int index = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (d[i] != INF) {				// INF가 아니면 감염되었다고 판단
				if(index == -1) index = i;	// 가장 큰 값의 index를 저장
				cnt++;						// 감염된 pc counting
			}

		}

		printf("%d %d\n", cnt, d[index]);
	}
}