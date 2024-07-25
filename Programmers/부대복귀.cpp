#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int visited[100004];
vector<int> graph[100004];

vector<int> bfs(int n, vector<int>& sources, int destination) {
	vector<int> res;
	visited[destination] = 1;
	queue<int> Q;
	Q.push(destination);

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		for (int nx : graph[x]) {
			if (visited[nx]) continue;
			visited[nx] = visited[x] + 1;
			Q.push(nx);
		}   // end of for nx
	}   // end of while

	for (int x : sources) {
		int dis = visited[x] - 1;
		res.push_back(visited[x] - 1);
	}   // end of sources
	return res;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
	vector<int> answer;

	for (vector<int> road : roads) {
		graph[road[0]].push_back(road[1]);
		graph[road[1]].push_back(road[0]);
	}   // end of for

	answer = bfs(n, sources, destination);
	return answer;
}