#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[1000004];

int bfs(int a, int b, int n) {
	queue<int> Q;
	Q.push(a);
	visited[a] = 1;

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		if (x == b) return visited[x] - 1;

		if (x + n <= 1000000 && visited[x + n] == 0) {
			Q.push(x + n);
			visited[x + n] = visited[x] + 1;
		}
		if (x * 2 <= 1000000 && visited[x * 2] == 0) {
			Q.push(x * 2);
			visited[x * 2] = visited[x] + 1;
		}
		if (x * 3 <= 1000000 && visited[x * 3] == 0) {
			Q.push(x * 3);
			visited[x * 3] = visited[x] + 1;
		}
	}

	return -1;
}

int solution(int x, int y, int n) {
	int answer = bfs(x, y, n);

	return answer;
}