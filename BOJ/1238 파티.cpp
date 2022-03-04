#include<cstdio>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[1001];	// ���� ���� ���� ����

void dijkstra(int start, int d[]) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// �켱���� ť �̿��Ͽ� �Ÿ��� ª�� ������ ���
	pq.push({ 0, start });
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
	int N, M, X;
	scanf("%d %d %d", &N, &M, &X);
	
	int d[1001] = { 0 };
	int back[1001] = { 0 };

	for (int i = 0; i < M; i++) {
		int a, b, time;
		scanf("%d %d %d", &a, &b, &time);
		graph[a].push_back({ b, time });
	}

	int result = -1;

	fill(back, back + N + 1, INF);
	dijkstra(X, back);				// ��Ƽ��ҿ��� ���ƿ��� ��� �̸� ���

	for (int i = 1; i <= N; i++) {
		fill(d, d + N + 1, INF);
		dijkstra(i, d);				// ���� �Ÿ� ���
		int sum = d[X];
		sum += back[i];
		result = sum > result? sum : result;
		
	}

	printf("%d\n", result);

}