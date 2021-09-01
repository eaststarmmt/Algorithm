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
		if (x == 'M') gen[i] = 1;		// 성별에 대한 정보 미리 받아놓기
		else gen[i] = 2;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c, {a, b} });
	}
	for (int i = 1; i <= N; i++) {	// 부모 초기화
		parent[i] = i;
	}

	sort(edge.begin(), edge.end());
	int result = 0;
	int cnt = 0;
	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		int cost = edge[i].first;

		if ((findParent(a) != findParent(b)) && gen[a] != gen[b]) {	// 부모가 다르고 성별이 다르면 union
			result += cost;
			unionParent(a, b);
			cnt++;
		}
	}
	if (cnt == N - 1)				// cnt가 N - 1 보다 작으면 고립된 노드가 있다는것을 의미함
		printf("%d\n", result);
	else
		printf("%d\n", -1);
}