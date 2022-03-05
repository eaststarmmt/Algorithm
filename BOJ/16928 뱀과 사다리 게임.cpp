#include<iostream>
#include<unordered_map>
#include<queue>
#define endl "\n"
using namespace std;
class Info {
public:
	int x, cnt;
	Info(int x, int cnt) {
		this->x = x;
		this->cnt = cnt;
	}	
};
int N, M;
unordered_map<int, int> ladder;
bool visited[101];
int res;
void bfs(int start) {
	queue<Info> Q;
	Q.push(Info(start, 0));
	visited[start] = true;
	while (!Q.empty()) {
		int x = Q.front().x;
		int cnt = Q.front().cnt;
		if (x > 100) continue;	// 100�� �Ѿ�� �̵� �Ұ�. �׳� ������
		else if (x == 100) {	// 100 �����ϸ� ó�� ������ �ּ� �Ÿ��̹Ƿ� ���� �� ����
			res = cnt;
			return;
		}
		Q.pop();
		for (int i = 1; i <= 6; i++) {
			if (!visited[x + i]) {
				visited[x + i] = true;
				if (ladder.find(x + i) != ladder.end()) {	// ��ٸ��� �쿡 �� ���
					Q.push(Info(ladder[x + i], cnt + 1));	// �ٷ� �� ��ġ�� �̵��ؼ� �湮 ó�� �� ť�� �ֱ�
					visited[ladder[x + i]] = true;
				}
				else {
					Q.push(Info(x + i, cnt + 1));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}	// ��ٸ� �Է�

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		ladder[u] = v;
	}	// �� �Է�

	bfs(1);
	cout << res << endl;
}