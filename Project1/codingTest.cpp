#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool visited[101];
vector<int> graph[101];

void bfs(int start) {
	queue<int> que;
	que.push(start);
	visited[start] = true;
	while (!que.empty()) {
		
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(1);
}