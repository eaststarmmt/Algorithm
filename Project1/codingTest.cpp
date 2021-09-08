#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long binarySearch(vector<long long> tree, long long start, long long end, long long target) {
	long long maxHeight = 0;
	while (start <= end) {
		long long mid = (start + end) / 2;	// 절단기 높이
		long long sum = 0;				// 자른 나무 높이 합
		for (int i = 0; i < tree.size(); i++) {
			if (tree[i] > mid) {
				sum += tree[i] - mid;
			}
		}
		if (sum >= target) {
			start = mid + 1;
			maxHeight = mid > maxHeight ? mid : maxHeight;
		}
		else end = mid - 1;
	}
	return maxHeight;
}

int main() {
	int N;
	long long M;
	scanf("%d %lld", &N, &M);
	vector<long long> tree;
	for (int i = 0; i < N; i++) {
		long long x;
		scanf("%lld", &x);
		tree.push_back(x);
	}
	sort(tree.begin(), tree.end());

	printf("%lld\n", binarySearch(tree, 0, tree[tree.size() - 1], M));
}