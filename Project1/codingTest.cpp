#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int binarySearch(vector<int> input, int start, int end, int target) {
	
	int maxValue = 0;

	while (start <= end) {
		int mid = (start + end) / 2;		// ���Ѱ��� Ȯ���� ����
		int sum = 0;
		for (int i = 0; i < input.size(); i++) {
			if (mid < input[i]) sum += mid;		// ���Ѱ� ���� ũ�� ���Ѱ� �ֱ�
			else sum += input[i];			// ������ �׳� �ֱ�
		}

		if (sum <= target) {				// ���� ���� �����̸� start �÷��� �� ū �� ������ �ִ��� ã��
			start = mid + 1;
			maxValue = mid > maxValue ? mid : maxValue;
		}
		else end = mid - 1;				// ���꺸�� ũ�� end�� �ٿ��� ���ǿ� ���纸��
	}
	return maxValue;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<int> input;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		input.push_back(x);
		sum += x;				// ����� ���ϱ� ���� �̸� ���� ���ص�
	}
	int M;				
	scanf("%d", &M);
	sort(input.begin(), input.end());
	
	if (sum <= M) {		// ���� ���� �����̸� �ִ밪 ���
		printf("%d\n", input[input.size() - 1]);
		return 0;
	}

	printf("%d\n", binarySearch(input, 0, input[input.size() - 1], M));
}