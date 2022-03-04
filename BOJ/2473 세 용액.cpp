#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int sol[5000];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &sol[i]);
	}	// end of input

	sort(sol, sol + N);
	int ans[3] = { 0 };	// ���� ����� �迭
	ll minVal = 50000000000;	// �ּҰ� ���
	for (int i = 0; i < N - 2; i++) {
		int start = i;
		int left = i + 1;
		int right = N - 1;
		while (left < right) {	// �������� ����
			ll sum = (ll)sol[start] + sol[left] + sol[right];	// ĳ���� ���ϸ� int�� ����� �� ����
			if (minVal > abs(sum)) {			// ���밪 �� ������ ����
				ans[0] = sol[start];
				ans[1] = sol[left];
				ans[2] = sol[right];
				minVal = abs(sum);
			}
			if (sum > 0) 	// ����� ��� right�� ������ ���ܼ� ���� �ٿ���
				right--;
			else if (sum < 0) // ������ ��� left�� �ڷ� �о ���� �÷���
				left++;
			else {		// 0 �̸� ������ �ϳ��� ����ϸ� �ǹǷ� �ٷ� ����
				printf("%d %d %d\n", ans[0], ans[1], ans[2]);
				return 0;
			}
		}
	}
	printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}