#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int m, n;
int graph[1000][1000];
queue<pair<int, int>> que;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void bfs() {
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || graph[nx][ny] == -1) continue;
			if (graph[nx][ny] == 0) {
				graph[nx][ny] = graph[x][y] + 1;
				que.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 1) que.push({ i, j });
				
		}
	}
	
	bfs();
	
	int result = graph[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}
			if (result < graph[i][j]) result = graph[i][j];
		}
	}
	cout << result - 1 << "\n";
}