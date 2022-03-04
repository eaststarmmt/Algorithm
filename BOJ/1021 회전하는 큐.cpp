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
	int count = 0;
	for (int i = 0; i < m; i++) {
		int index, x;
		cin >> x;
		for (int j = 0; j < deque.size(); j++) {
			if (deque[j] == x) {
				index = j;
				break;
			}
		}
		while (1) {
			if (deque.front() == x) {
				deque.pop_front();
				break;
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
	
	}
	cout << count << endl;
}