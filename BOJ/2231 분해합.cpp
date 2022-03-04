#include<iostream>
using namespace std;

int main() {
	int target;
	cin >> target;

	for (int i = 1; i < target; i++) {
		int part = i;
		int sum = i;
		while (part) {
			sum += part % 10;
			part /= 10;
		}
		if (sum == target) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}