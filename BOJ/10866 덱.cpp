#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int test;
	deque<int> deque;
	cin >> test;
	for (int i = 0; i < test; i++) {
		string com;
		cin >> com;
		if (com == "push_front") {
			int x;
			cin >> x;
			deque.push_front(x);
		}
		else if (com == "push_back") {
			int x;
			cin >> x;
			deque.push_back(x);
		}
		else if (com == "pop_back") {
			if (deque.empty()) cout << -1 << "\n";
			else {
				cout << deque.back() << "\n";
				deque.pop_back();
			}
		}
		else if (com == "pop_front") {
			if (deque.empty()) cout << -1 << "\n";
			else {
				cout << deque.front() << "\n";
				deque.pop_front();
			}
		}
		else if (com == "size") cout << deque.size() << "\n";
		else if (com == "empty") {
			if (deque.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (com == "front") {
			if (deque.empty()) cout << -1 << "\n";
			else cout << deque.front() << "\n";
		}
		else if (com == "back") {
			if (deque.empty()) cout << -1 << "\n";
			else cout << deque.back() << "\n";
		}
	}
}