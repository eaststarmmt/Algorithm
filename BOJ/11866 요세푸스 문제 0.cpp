#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		que.push(i);
	}
	cout << '<';
	while (!que.empty()) {
		for (int i = 0; i < k - 1; i++) {
			int x = que.front();
			que.pop();
			que.push(x);
		}
		cout << que.front();
		que.pop();
		if (!que.empty()) cout << ", ";
		else cout << '>' << endl;
	}
}