#include<iostream>
using namespace std;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) cout << from << ' ' << to << "\n";
	else {
		hanoi(n - 1, from, to, by);
		cout << from << ' ' << to << "\n";
		hanoi(n - 1, by, from, to);
	}
}

int hanoiCount(int n) {
	if (n == 1) return 1;
	else return hanoiCount(n - 1) * 2 + 1;
}

int main() {
	int n;
	cin >> n;
	cout << hanoiCount(n) << "\n";
	hanoi(n, 1, 2, 3);
}