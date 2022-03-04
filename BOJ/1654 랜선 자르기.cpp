#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int binarySearch(vector<long long> arr, long long target, long long start, long long end) {
	long long mid;
	long long max = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i] / mid;
		}
		if (target > sum) end = mid - 1;
		else {		// 작게 잘랐거나 맞게 자른 경우 이므로 답 보다 커질일은 없음
			start = mid + 1;
			if (mid > max) max = mid;
		}
	}
	return max;
}

int main() {
	long long k, n;
	scanf("%lld %lld", &k, &n);
	vector<long long> vec;
	for (int i = 0; i < k; i++) {
		long long x;
		scanf("%lld", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	printf("%lld\n", binarySearch(vec, n, 1, vec[vec.size() - 1]));
}