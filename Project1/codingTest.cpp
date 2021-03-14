#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

int count;

int binarySearch(vector<int> *arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> card;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		card.push_back(x);
	}
	int m;
	scanf("%d", &m);
	vector<int> search;
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		search.push_back(x);
	}
	sort(card.begin(), card.end());
	for (int i = 0; i < m; i++) {
		
	}
}