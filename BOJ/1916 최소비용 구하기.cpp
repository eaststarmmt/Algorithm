#include<stdio.h>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;
vector<pair<int, int>> graph[1001]; // ù��° �� �ι�° �� ���� Ȯ���� �ϱ�. ũ��� ��� ������ ���
int d[1001];
// �׳� ���ͽ�Ʈ�� �ܿ����� Ǫ�� ����
void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start }); // ���⼭ ù��° ���� �Ÿ����� ����ȣ���� �� ����ϱ�. �򰥸��� ���� ¥����
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