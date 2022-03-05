#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define endl "\n"
using namespace std;

bool visited[300001];
vector<int> graph[300001];
int V, E, K, X;
vector<int> result;	// ��� ������������ �϶� �ؼ�

class info {	// Ŭ���� IDE ���� ©������ �غ��� ����
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
	while (!Q.empty()) {	// ����� bfs 
		int x = Q.front().x;
		int dis = Q.front().dis;
		Q.pop();
		if (dis == K) result.push_back(x);	// �Ÿ��� K ��� ����
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