#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> edge;
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
	cin >> N >> M;
	vector<int> gen(N + 1);
	for (int i = 1; i <= N; i++) {
		char x;
		cin >> x;
		if (x == 'M') gen[i] = 1;		// ������ ���� ���� �̸� �޾Ƴ���
		else gen[i] = 2;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c, {a, b} });
	}
	for (int i = 1; i <= N; i++) {	// �θ� �ʱ�ȭ
		parent[i] = i;
	}

	sort(edge.begin(), edge.end());
	int result = 0;
	int cnt = 0;
	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		int cost = edge[i].first;

		if ((findParent(a) != findParent(b)) && gen[a] != gen[b]) {	// �θ� �ٸ��� ������ �ٸ��� union
			result += cost;
			unionParent(a, b);
			cnt++;
		}
	}
	if (cnt == N - 1)				// cnt�� N - 1 ���� ������ ���� ��尡 �ִٴ°��� �ǹ���
		printf("%d\n", result);
	else
		printf("%d\n", -1);
}