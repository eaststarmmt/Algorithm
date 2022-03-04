#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int parent[100001];
vector<pair<int, pair<int, int>>> edges;

int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	int n, m;
	int maxCost = 0;		// ũ�罺Į Ǯ�� ���߿� ���� ū ���� ã�� �뵵
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		edges.push_back({ cost, {a, b} });
	}
	sort(edges.begin(), edges.end());
	
	int result = 0;

	for (int i = 0; i < m; i++) {
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		int cost = edges[i].first;
		if (findParent(a) != findParent(b)) {
			result += cost;
			unionParent(a, b);
			maxCost = max(cost, maxCost);
		}
	}
	printf("%d\n", result - maxCost);	// �������� ���� ū ������ ������
}