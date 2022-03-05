#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int N;
bool visited[3001];
bool cycleLine[3001];
vector<int> graph[3001];
vector<int> res;
bool isCycle;

void bfs(int start) {
	queue<pair<int, int>> Q;
	Q.push({ start, 0 });
	visited[start] = true;
	while (!Q.empty()) {
		int x = Q.front().first;
		int dis = Q.front().second;
		Q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (cycleLine[y]) {			// 사이클 최단 경로 찾았으면 값 저장
				res.push_back(dis + 1);
				return;
			}
			if (!visited[y]) {
				Q.push({ y, dis + 1 });
				visited[y] = true;
			}
		}
	}
}

void dfs(int now, int len, int start) {
	if (now == start && len >= 2) {	// 사이클 형성 됐을때. 길이가 1 이하면 순환이 아니라 왕복
		isCycle = true;
		return;
	}
	else if (now == start && len != 0) return;	
	visited[now] = true;
	for (int i = 0; i < graph[now].size(); i++) {
		if (isCycle) return;
		int x = graph[now][i];
		if (!visited[x]) {		// 방문 안했을 경우만 탐색
			dfs(x, len + 1, start);
		}
		else if(x == start && len >= 2) {	// 다음 갈 곳이 시작점이고 현재 길이가 2 이상이면 마무리 작업하러 감
			dfs(x, len + 1, start);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {	// 사이클 체크
		memset(visited, false, sizeof(visited));	// visited 초기화
		isCycle = false;
		dfs(i, 0, i);
		if (isCycle) {	// 순환선 따로 체크
			cycleLine[i] = true;	// 한번에 경로 넣고 체크하고 이런건 도저히 답이 안보임
		}
	}	// end of cycle
	
	for (int i = 1; i <= N; i++) {
		if (cycleLine[i])	// 순환선에 포함 되면 0
			res.push_back(0);
		else {				// 아닌 경우 다시 거리 측정
			memset(visited, false, sizeof(visited));
			bfs(i);
		}
	}
	for (auto i : res) {
		printf("%d ", i);
	}
	printf("\n");
}