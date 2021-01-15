#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		bool reverse = false;
		bool error = false;
		string p;
		cin >> p;
		int num;
		cin >> num;
		string input;
		cin >> input;
		deque<int> deque;
		string x;
		for (int j = 0; j < input.size(); j++) {
			if (input[j] >= '0' && input[j] <= '9') {
				x += input[j];
			}
			else {
				if (j == 0) continue;
				deque.push_back(stoi(x));
				x.clear();
			}
		}

		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'R') {
				reverse = !reverse;
			}
			else {
				if(!deque.empty()) {
					if (reverse) {
						deque.pop_back();
					}
					else {
						deque.pop_front();
					}
				}
				else error = true;
			}
		}
		if (error) cout << "error" << "\n";
		else {
			cout << '[';
			int cnt = deque.size();
			if (!reverse) {
				for (int j = 0; j < cnt; j++) {
					cout << deque.front();
					deque.pop_front();
					if (!deque.empty()) cout << ',';
				}
			}
			else {
				for (int j = 0; j < cnt; j++) {
					cout << deque.back();
					deque.pop_back();
					if (!deque.empty()) cout << ',';
				}
			}
			cout << "]\n";
		}
		
	}
}