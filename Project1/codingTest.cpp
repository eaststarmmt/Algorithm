#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long binarySearch(vector<long long> tree, long long start, long long end, long long target) {
	long long maxHeight = 0;
	while (start <= end) {
		long long mid = (start + end) / 2;	// 절단기 높이
		long long sum = 0;					// 자른 나무 높이 합
		for (int i = 0; i < tree.size(); i++) {
			if (tree[i] > mid) {		// 절단기보다 트리의 높이가 더 높으면 자른거 더 함
				sum += tree[i] - mid;
			}
		}
		if (sum >= target) {	// sum이 더 크다면 절단기 높이가 낮았다는 의미 이므로 start 값 키워서 mid값 높임
			start = mid + 1;	
			maxHeight = mid > maxHeight ? mid : maxHeight;	// sum이 크거나 같을때로 해야 최대값이 제대로 들어감
		}
		else end = mid - 1;		// sum이 더 작으면 절단기 높이가 높았다는 의미 이므로 end 값 줄여서 mid값 줄임
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
	sort(tree.begin(), tree.end());			// 바이너리 서치는 기본적으로 sort가 되어 있어야 함

	printf("%lld\n", binarySearch(tree, 0, tree[tree.size() - 1], M));
}