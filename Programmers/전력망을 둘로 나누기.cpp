#include <string>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

bool visited[101];
int n;
int cnt1, cnt2;
vector<int> graph[101];

void dfs(int x, int ign, int& cnt) {
	cnt++;
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y] && y != ign) {   // 방문한 적 없으면서 끊어야 되는 노드가 아닌 경우
			dfs(y, ign, cnt);
		}
	}   // end of for
}

int solution(int n, vector<vector<int>> wires) {
	int answer = 1e9;
	n = wires.size();

	for (int i = 0; i < wires.size(); i++) { // 트리 정보 저장
		graph[wires[i][0]].push_back(wires[i][1]);
		graph[wires[i][1]].push_back(wires[i][0]);
	}

	for (int i = 0; i < wires.size(); i++) {
		cnt1 = cnt2 = 0;
		memset(visited, false, sizeof(visited));
		dfs(wires[i][0], wires[i][1], cnt1);
		dfs(wires[i][1], wires[i][0], cnt2);
		int dif = abs(cnt1 - cnt2);
		answer = dif < answer ? dif : answer;
	}   // end of for

	return answer;
}