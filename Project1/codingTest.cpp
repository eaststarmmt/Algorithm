#include<iostream>
#include<queue>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		else {
			return abs(a) > abs(b);
		}
	}
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}