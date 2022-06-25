#include <string>
#include <vector>

using namespace std;
bool visited[200];

void dfs(int x, vector<vector<int>>& graph) {
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		if (x == i) continue;    // 자기 자신은 볼 필요 없음
		if (!visited[i] && graph[x][i] == 1) {
			dfs(i, graph);
		}
	}   // end of for i
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < computers.size(); i++) {
		if (!visited[i]) {   // 방문한 적 없으면 무조건 하나의 네트워크가 추가됨
			dfs(i, computers);
			answer++;
		}
	}   // end of for i

	return answer;
}