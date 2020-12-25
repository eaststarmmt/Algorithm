#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector <int> he;
	for (int i = 0; i < 9; i++) {
		int x;
		cin >> x;
		he.push_back(x);
	}
	sort(he.begin(), he.end());
	while (next_permutation(he.begin(), he.end())) {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += he[i];
			if (sum == 100) {
				for (int j = 0; j < 7; j++) cout << he[j] << endl;
				return 0;
			}
		}
	}
}