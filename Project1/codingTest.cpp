#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> card;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		card.push_back(x);
	}
	vector <int> result;
	sort(card.begin(), card.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = card[i] + card[j] + card[k];
				if (sum <= m) result.push_back(sum);
			}
		}
	}
	cout << *max_element(result.begin(), result.end()) << endl;
}