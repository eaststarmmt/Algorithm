#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, top;
	cin >> n;
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		que.push(i);
	}
	while (que.size() != 1) {
		que.pop();
		top = que.front();
		que.pop();
		que.push(top);
	}
	cout << que.front() << endl;
}