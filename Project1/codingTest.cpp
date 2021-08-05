#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int v;
vector<pair<int, int>> dis[100001];		// <노드 번호, 거리> 형태로 저장
bool visited[100001];
int radius;
int farIdx;

void dfs(int x, int sum) {
	visited[x] = true;
	if (radius < sum) {				// 가장 멀리 있는 곳의 인덱스 저장
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

	for (int i = 0; i < v; i++) {
		int a;
		scanf("%d", &a);
		while (1) {
			int b, c;
			scanf("%d", &b);
			if (b == -1) break;
			scanf("%d", &c);
			dis[a].push_back({ b, c });
		}
	}

	dfs(1, 0);								// 아무데서나 dfs를 한번 돌려서 가장 먼 곳 인덱스 잡음
	memset(visited, false, sizeof(visited));	// false 값으로 초기화
	dfs(farIdx, 0);							// 가장 먼 인덱스에서 다시 dfs 돌려서 최종값 찾기
		
	printf("%d\n", radius);
}