#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

bool cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

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

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	sort(costs.begin(), costs.end(), cmp);  // 비용 기준으로 오름차순. 첫번째 부모가 cost 최소값이 되도록

	for (int i = 0; i < n; i++) {    // 부모를 자기 자신으로 초기화
		parent[i] = i;
	}   // end of for

	for (int i = 0; i < costs.size(); i++) {
		int a = costs[i][0];
		int b = costs[i][1];
		int cost = costs[i][2];

		if (findParent(a) != findParent(b)) {    // 부모가 다를때만. 즉 사이클 방지
			unionParent(a, b);
			answer += cost;     // cost 기준 오름차순이라 
		}
	}   // end of for
	return answer;
}