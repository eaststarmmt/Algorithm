#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;

vector<pair<int, pair<int, int>>> edge;		// ������� �������� �����ϱ� ���� cost�� ���� �տ� ��
int d[1001];
int parent[1001];

int findParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int main() {
	
	int N, M;
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge.push_back({ c, {a, b} });
	}
	fill(d, d + N, INF);
	sort(edge.begin(), edge.end());

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	int result = 0;

	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		int cost = edge[i].first;

		if (findParent(a) != findParent(b)) {	// �θ� �������� ����Ǹ� ����Ŭ �߻�
			unionParent(a, b);
			result += cost;
		}
	}
	printf("%d\n", result);
}