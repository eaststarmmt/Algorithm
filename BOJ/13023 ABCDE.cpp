#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> graph[2000];
int N, M, a, b;
int visited[2000];
bool res;

void dfs(int cnt, int x) {
	if (res) return;
	if (cnt >= 5) {
		res = true;
		return;
	}

	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (visited[y]) continue;
		dfs(cnt + 1, y);
	}
	visited[x] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}	// end of for

	for (int i = 0; i < N; i++) {
		if (res) break;
		memset(visited, 0, sizeof(visited));
		dfs(1, i);
	}

	cout << res << '\n';
	
}