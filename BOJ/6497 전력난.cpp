#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;

vector<pair<int, pair<int, int>>> edge;
int parent[200001];

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
	int m, n;	// M ���� ��, N ���� ��
	int sum;
	int save;
	while (1) {

		
		scanf("%d %d", &m, &n);

		if (m == 0 && n == 0) break;		// Ż�� ����

		sum = 0;

		for (int i = 0; i < n; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			edge.push_back({ z, {x, y} });
			sum += z;							// �Է� �����鼭 �̸� ���� ����
		}
		sort(edge.begin(), edge.end());

		for (int i = 0; i < m; i++) {
			parent[i] = i;
		}

		save = 0;

		for (int i = 0; i < edge.size(); i++) {
			int a = edge[i].second.first;
			int b = edge[i].second.second;
			int cost = edge[i].first;
			if (findParent(a) != findParent(b)) {
				unionParent(a, b);
				save += cost;			// MST ���
			}
		}

		printf("%d\n", sum - save);	// �� �տ��� MST�� ����
		edge.clear();
	}

}