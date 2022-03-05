#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

vector<int> graph[1001];
bool visited[1001];
int V, E;

bool dfs(int x) {
	if (visited[x]) return false;	// 방문한적 있으면 이미 했으므로 false
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {	// x에 연결된 애들 다 방문
		dfs(graph[x][i]);
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;

	for (int i = 0; i < E; i++) {	// x에서 y, y에서 x 둘다 넣기. 방향성 없음
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}	// end of input

	int cnt = 0;
	for (int i = 1; i <= V; i++) {
		if (dfs(i)) cnt++;		// dfs 가능하면 카운팅
	}
	cout << cnt << endl;
}