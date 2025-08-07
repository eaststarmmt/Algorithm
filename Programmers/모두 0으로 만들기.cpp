#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> graph[300004];
vector<long long> sum;

long long dfs(int x, int parent, vector<int>& a) {
	long long res = 0;   // 횟수. 총 합을 보내야 돼서 현재 값은 리턴 직전에 더해야 됨

	for (int next : graph[x]) {
		if (next == parent) continue;    // 부모면 무시
		res += dfs(next, x, a); // 자식까지 왔던 횟수 더하기
		sum[x] += sum[next];    // 누적되는 합 계속 더하기
	}   // end of for graph

	res += abs(sum[x]);
	return res;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
	long long answer = -2;
	sum = vector<long long>(a.begin(), a.end());

	for (vector<int> v : edges) {
		int a = v[0];
		int b = v[1];
		graph[a].push_back(b);
		graph[b].push_back(a);
	}   // end of for edges

	answer = dfs(0, 0, a);
	return sum[0] ? -1 : answer;
}