#include<iostream>
#include<queue>
using namespace std;

int main() {
	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		int n, m;
		cin >> n >> m;
		queue<pair<int, int>> que;
		priority_queue<int, vector<int>, less<int>> pq;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			que.push({ x, j });
			pq.push(x);
		}
		int count = 0;
		while (!que.empty()) {
			if (que.front().first != pq.top()) {
				que.push(que.front());
				que.pop();
			}
			else {
				count++;
				pq.pop();
				if (que.front().second == m) {
					cout << count << endl;
					break;
				}
				que.pop();
			}
		}
	}
}