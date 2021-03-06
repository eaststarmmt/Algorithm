#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int binarySearch(vector<int> &vec, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (target == vec[mid]) return 1;
		else if (vec[mid] < target) start = mid + 1;
		else end = mid - 1;
	}
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> vec, target;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		target.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", binarySearch(vec, target[i], 0, n - 1));
	}
	return 0;
}