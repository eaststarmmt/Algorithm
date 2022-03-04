#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> graph[1001];
bool dfsVisited[1001];
bool bfsVisited[1001];

void dfs(int x) {
	dfsVisited[x] = true;
	cout << x;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!dfsVisited[y]) {
			cout << ' ';
			dfs(y);
		}
	}
}

void bfs(int start) {
	queue<int> que;
	que.push(start);
	bfsVisited[start] = true;
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!bfsVisited[y]) {
				bfsVisited[y] = true;
				que.push(y);
			}
		}

	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(v);
	cout << "\n";
	bfs(v);
	cout << "\n";
}