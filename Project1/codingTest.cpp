#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

long long binarySearch(vector<long long> vec, long long target, long long start, long long end) {
	long long sum;
	long long max = 0;
	while (start <= end) {
		sum = 0;
		long long mid = (start + end) / 2;
		for (int i = 0; i < vec.size(); i++) {
			if(vec[i] > mid) sum += vec[i] - mid;
		}
		if (target > sum) end = mid - 1;
		else {		//작은 것 중 최대라고 기억하기
			start = mid + 1;
			if (max < mid) max = mid;
		}
	}
	return max;
}

int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	vector<long long> vec;
	for (int i = 0; i < n; i++) {
		long long x;
		scanf("%lld", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	printf("%lld \n", binarySearch(vec, m, 0, vec[0]));
}