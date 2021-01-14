#include<iostream>
#include<deque>
#include<queue>
using namespace std;

int main() {
	deque<int> deque;
	queue<int> que;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		deque.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		que.push(x);
	}
	int count = 0;
	while (!que.empty()) {
		int index;
		for (int i = 0; i < deque.size() < i++;) {
			deque[i] == que.front();
			index = i;
		}
		if (deque.front() == que.front()) {
			deque.pop_front();
			que.pop();
		}
		else {
			count++;
			if (index > deque.size() - index) {
				deque.push_front(deque.back());
				deque.pop_back();
			}
			else {
				deque.push_back(deque.front());
				deque.pop_front();
			}
		}
	}
	cout << count << endl;
}