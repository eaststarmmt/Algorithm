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
			if (cycleLine[y]) {			// ����Ŭ �ִ� ��� ã������ �� ����
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
	if (now == start && len >= 2) {	// ����Ŭ ���� ������. ���̰� 1 ���ϸ� ��ȯ�� �ƴ϶� �պ�
		isCycle = true;
		return;
	}
	else if (now == start && len != 0) return;	
	visited[now] = true;
	for (int i = 0; i < graph[now].size(); i++) {
		if (isCycle) return;
		int x = graph[now][i];
		if (!visited[x]) {		// �湮 ������ ��츸 Ž��
			dfs(x, len + 1, start);
		}
		else if(x == start && len >= 2) {	// ���� �� ���� �������̰� ���� ���̰� 2 �̻��̸� ������ �۾��Ϸ� ��
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

	for (int i = 1; i <= N; i++) {	// ����Ŭ üũ
		memset(visited, false, sizeof(visited));	// visited �ʱ�ȭ
		isCycle = false;
		dfs(i, 0, i);
		if (isCycle) {	// ��ȯ�� ���� üũ
			cycleLine[i] = true;	// �ѹ��� ��� �ְ� üũ�ϰ� �̷��� ������ ���� �Ⱥ���
		}
	}	// end of cycle
	
	for (int i = 1; i <= N; i++) {
		if (cycleLine[i])	// ��ȯ���� ���� �Ǹ� 0
			res.push_back(0);
		else {				// �ƴ� ��� �ٽ� �Ÿ� ����
			memset(visited, false, sizeof(visited));
			bfs(i);
		}
	}
	for (auto i : res) {
		printf("%d ", i);
	}
	printf("\n");
}