#include<iostream>
using namespace std;
int graph[50][50];
int m, n, k, cnt;

bool dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n) return false;
	if (graph[x][y] == 1) {
		graph[x][y] = 0;
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			graph[x][y] = 1;
		}
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (dfs(j, k)) cnt++;
			}
		}
		cout << cnt << "\n";
		
		if(i < t - 1) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < n; k++) graph[j][k] = 0;
			}
			cnt = 0;
		}
	}

}