#include<stdio.h>
#include<vector>
#include<algorithm>
#define MIN -1e9
using namespace std;
						// ��Ģ ���µ�. �׳� �� �غ��� ����
int main() {
	int N;
	scanf("%d", &N);
	vector<int> seq;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		seq.push_back(x);
	}
	sort(seq.begin(), seq.end());
	int maxSum = MIN;

	do {
		int sum = 0;
		for (int i = 1; i < N; i++) {
			sum += abs(seq[i] - seq[i - 1]);
		}
		maxSum = max(sum, maxSum);
	} while (next_permutation(seq.begin(), seq.end()));		// next permutaion�� �̿��ؼ� ���������� �ϳ��� ��� ��� �� ����

	printf("%d\n", maxSum);
}