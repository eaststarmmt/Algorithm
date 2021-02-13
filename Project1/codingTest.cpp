#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int n, m;
int graph[100][100];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1 ,1 };

int bfs(int x, int y) {
	queue<pair<int, int>> que;
	que.push({ x, y });
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				que.push({ nx, ny });
			}
		}
	}
	return graph[n - 1][m - 1];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	cout << bfs(0, 0) << "\n";
}