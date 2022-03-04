#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int v;
vector<pair<int, int>> dis[100001];		// <��� ��ȣ, �Ÿ�> ���·� ����
bool visited[100001];
int radius;
int farIdx;

void dfs(int x, int sum) {
	visited[x] = true;
	if (radius < sum) {				// ���� �ָ� �ִ� ���� �ε��� ����
		radius = sum;
		farIdx = x;
	}

	for (int i = 0; i < dis[x].size(); i++) {
		int y = dis[x][i].first;
		if (!visited[y]) {
			dfs(y, sum + dis[x][i].second);
		}
	}
}

int main() {
	scanf("%d", &v);

	for (int i = 0; i < v - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dis[a].push_back({ b, c });
		dis[b].push_back({ a, c });
		
	}

	dfs(1, 0);								// �ƹ������� dfs�� �ѹ� ������ ���� �� �� �ε��� ����
	memset(visited, false, sizeof(visited));	// false ������ �ʱ�ȭ
	dfs(farIdx, 0);							// ���� �� �ε������� �ٽ� dfs ������ ������ ã��

	printf("%d\n", radius);
}