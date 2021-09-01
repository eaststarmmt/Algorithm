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
		vector<vector<pair<int, int>>> graph(n + 1);	// �迭 ���·δ� �Ѿ�� �ʾƼ� vector�� �������� ũ�⸦ �����ؼ� ��� �ʱ�ȭ
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
			if (d[i] != INF) {				// INF�� �ƴϸ� �����Ǿ��ٰ� �Ǵ�
				if(index == -1) index = i;	// ���� ū ���� index�� ����
				cnt++;						// ������ pc counting
			}

		}

		printf("%d %d\n", cnt, d[index]);
	}
}