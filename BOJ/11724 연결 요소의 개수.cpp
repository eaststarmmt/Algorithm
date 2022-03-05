#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

vector<int> graph[1001];
bool visited[1001];
int V, E;

bool dfs(int x) {
	if (visited[x]) return false;	// �湮���� ������ �̹� �����Ƿ� false
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {	// x�� ����� �ֵ� �� �湮
		dfs(graph[x][i]);
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;

	for (int i = 0; i < E; i++) {	// x���� y, y���� x �Ѵ� �ֱ�. ���⼺ ����
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}	// end of input

	int cnt = 0;
	for (int i = 1; i <= V; i++) {
		if (dfs(i)) cnt++;		// dfs �����ϸ� ī����
	}
	cout << cnt << endl;
}