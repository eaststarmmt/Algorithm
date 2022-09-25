#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[24][24][24];   // 위치 양 늑대
vector<int> graph[24];
int answer;
void dfs(int now, int sheep, int wolf, vector<int>& info) {
	answer = max(sheep, answer);
	for (int next : graph[now]) {
		if (info[next] == 0) {	// 양인 경우
			if (visited[next][sheep + 1][wolf]) {
				continue;
			}
			info[next] = -1;
			visited[next][sheep + 1][wolf] = true;
			dfs(next, sheep + 1, wolf, info);
			visited[next][sheep + 1][wolf] = false;
			info[next] = 0;

		}
		else if (info[next] == 1) {		// 늑대인 경우
			if (visited[next][sheep][wolf + 1] || sheep <= wolf + 1) {
				continue;
			}
			info[next] = -1;
			visited[next][sheep][wolf + 1] = true;
			dfs(next, sheep, wolf + 1, info);
			visited[next][sheep][wolf + 1] = false;
			info[next] = 1;
		}
		else {		// 비어있는 경우
			if (visited[next][sheep][wolf]) {
				continue;
			}
			visited[next][sheep][wolf] = true;
			dfs(next, sheep, wolf, info);
			visited[next][sheep][wolf] = false;
		}
	}   // end of for
}

int solution(vector<int> info, vector<vector<int>> edges) {
	for (int i = 0; i < edges.size(); i++) {
		int from = edges[i][0];
		int to = edges[i][1];
		graph[from].push_back(to);
		graph[to].push_back(from);
	}   // end of for graph
	info[0] = -1;	// -1로 비어있음을 표시
	visited[0][1][0] = true;
	dfs(0, 1, 0, info);

	return answer;
}