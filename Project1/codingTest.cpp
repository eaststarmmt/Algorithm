<<<<<<< HEAD
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long binarySearch(vector<long long> tree, long long start, long long end, long long target) {
	long long maxHeight = 0;
	while (start <= end) {
		long long mid = (start + end) / 2;	// ���ܱ� ����
		long long sum = 0;					// �ڸ� ���� ���� ��
		for (int i = 0; i < tree.size(); i++) {
			if (tree[i] > mid) {		// ���ܱ⺸�� Ʈ���� ���̰� �� ������ �ڸ��� �� ��
				sum += tree[i] - mid;
			}
		}
		if (sum >= target) {	// sum�� �� ũ�ٸ� ���ܱ� ���̰� ���Ҵٴ� �ǹ� �̹Ƿ� start �� Ű���� mid�� ����
			start = mid + 1;	
			maxHeight = mid > maxHeight ? mid : maxHeight;	// sum�� ũ�ų� �������� �ؾ� �ִ밪�� ����� ��
		}
		else end = mid - 1;		// sum�� �� ������ ���ܱ� ���̰� ���Ҵٴ� �ǹ� �̹Ƿ� end �� �ٿ��� mid�� ����
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
	sort(tree.begin(), tree.end());			// ���̳ʸ� ��ġ�� �⺻������ sort�� �Ǿ� �־�� ��

	printf("%lld\n", binarySearch(tree, 0, tree[tree.size() - 1], M));
=======
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
		else {		//���� �� �� �ִ��� ����ϱ�
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
>>>>>>> 4160c68f1305e84872a34f0a19487a8d79783c6d
}