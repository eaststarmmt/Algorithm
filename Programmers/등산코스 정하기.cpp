#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int>> graph[50001];
bool isSummit[50001];
int dist[500001];

struct cmp {
	bool operator() (pair<int, int>& A, pair<int, int>& B) {
		return A.second > B.second;
	}
};

bool cmp_res(pair<int, int>& A, pair<int, int>& B) {
	if (A.second == B.second) {
		return A.first < B.first;
	}
	return A.second < B.second;
}

pair<int, int> dijkstra(vector<int>& gates) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (int gate : gates) {
		dist[gate] = 0;
		pq.push({ gate, 0 });
	}   // end of for gate

	vector<pair<int, int>> res;

	while (!pq.empty()) {
		int now = pq.top().first;
		int cost = pq.top().second; // 지금까지 경로 중 최댓값을 들고 오고 있음
		pq.pop();

		if (isSummit[now]) {	// 산봉우리 갔으면 여기까지 최댓값 저장하면 됨
			res.push_back({ now, cost });
			continue;
		}

		if (dist[now] < cost) {  // 이미 intensity가 더 커버리면 할 필요 없음
			continue;
		}

		for (pair<int, int> node : graph[now]) {
			int next = node.first;
			int intensity = node.second;

			if (dist[next] != -1 && dist[next] <= max(intensity, cost)) {     // 저장된 값이 이미 최소이면 무시. 방문한적 없으면 무조건 가야 됨
				continue;
			}
			dist[next] = max({ intensity, cost });
			pq.push({ next, dist[next] });
		}

	}   // end of while

	sort(res.begin(), res.end(), cmp_res);
	return res[0];
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;
	memset(dist, -1, sizeof(dist));
	for (vector<int> path : paths) {
		int from = path[0];
		int to = path[1];
		int cost = path[2];

		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}   // end of for paths

	for (int summit : summits) {
		isSummit[summit] = true;
	}   // end of for summit

	pair<int, int> res = dijkstra(gates);
	answer = { res.first, res.second };
	return answer;
}