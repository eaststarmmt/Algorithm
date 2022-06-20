#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Info {
	int x, dis;
};
vector<int> graph[20001];
bool visited[20001];
int max_dis;

void bfs(vector<vector<int>>& edge, int& answer) {
	queue<Info> Q;
	visited[1] = true;
	Q.push({ 1, 0 });

	while (!Q.empty()) {
		int x = Q.front().x;
		int dis = Q.front().dis;
		Q.pop();

		if (dis > max_dis) {  // 최댓값 바뀌면 갱신
			answer = 1;
			max_dis = dis;
		}
		else if (dis == max_dis) { // 최대값과 같으면 카운팅
			answer++;
		}

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				visited[y] = true;
				Q.push({ y, dis + 1 });
			}
		}
	}   // end of while Q
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	for (int i = 0; i < edge.size(); i++) {
		int from = edge[i][0];
		int to = edge[i][1];
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	bfs(edge, answer);
	return answer;
}