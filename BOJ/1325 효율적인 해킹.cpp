#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool visited[10004];
vector<int> graph[10004];

int N, M;

int dfs(int x) {
	visited[x] = true;
	int ret = 1;

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (visited[y]) continue;
		ret += dfs(y);
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[B].push_back(A);
	}	// end of for

	int max_cnt = 0;
	vector<int> res;
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		int cnt = dfs(i);
		if (cnt > max_cnt) {
			res.clear();
			res.push_back(i);
			max_cnt = cnt;
		}
		else if (max_cnt == cnt) {
			res.push_back(i);
		}
	}

	for (int x : res) {
		cout << x << ' ';
	}
	return 0;
}