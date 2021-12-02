#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define endl "\n"
using namespace std;

bool visited[300001];
vector<int> graph[300001];
int V, E, K, X;
vector<int> result;	// 결과 오름차순으로 하라 해서

class info {	// 클래스 IDE 없이 짤때까지 해보기 위함
public:
	int x, dis;
	info(int x, int dis) {	
		this->x = x;
		this->dis = dis;
	}
};

void bfs(int start) {
	queue<info> Q;
	Q.push(info(start, 0));
	visited[start] = true;
	while (!Q.empty()) {	// 평범한 bfs 
		int x = Q.front().x;
		int dis = Q.front().dis;
		Q.pop();
		if (dis == K) result.push_back(x);	// 거리가 K 라면 저장
		for (int i = 0; i < graph[x].size(); i++) {
			if (!visited[graph[x][i]]) {
				Q.push(info(graph[x][i], dis + 1));
				visited[graph[x][i]] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E >> K >> X;
	for (int i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}	// end of input
	
	bfs(X);
	if (result.empty()) {
		cout << -1 << endl;
		return 0;
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}