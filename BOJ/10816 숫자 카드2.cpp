#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m;
int main() {
	scanf("%d", &n);
	vector<int> card;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		card.push_back(x);
	}
	scanf("%d", &m);
	vector<int> search;
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		search.push_back(x);
	}
	sort(card.begin(), card.end());
	for (int i = 0; i < m; i++) {
		printf("%d ", upper_bound(card.begin(), card.end(), search[i]) - lower_bound(card.begin(), card.end(), search[i]));
	}
}