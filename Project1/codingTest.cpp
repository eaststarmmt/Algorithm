#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int graph[25][25];
int n;
vector<int> sum;
int cnt = 0;
int complex = 1;
bool visited[25][25];

bool dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) return false;
	if (visited[x][y]) return false;
	visited[x][y] = true;
	if (graph[x][y] > 0 ) {
		graph[x][y] = complex;
		cnt++;
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dfs(i, j)) {
				complex++;
				sum.push_back(cnt);
			}
			cnt = 0;
		}
	}
	sort(sum.begin(), sum.end());
	cout << complex - 1 << "\n";
	for (int i = 0; i < sum.size(); i++) {
		cout << sum[i] << "\n";
	}
}