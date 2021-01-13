#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	queue<int> que;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string com;
		cin >> com;
		if (com == "push") {
			int x;
			cin >> x;
			que.push(x);
		}
		else if (com == "pop") {
			if (que.empty()) cout << -1 << '\n';
			else {
				cout << que.front() << '\n';
				que.pop();
			}
		}
		else if (com == "size") {
			cout << que.size() << '\n';
		}
		else if (com == "empty") {
			if (que.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (com == "front") {
			if (que.empty()) cout << -1 << '\n';
			else cout << que.front() << '\n';
		}
		else {
			if (que.empty()) cout << -1 << '\n';
			else cout << que.back() << '\n';
		}
	}
}