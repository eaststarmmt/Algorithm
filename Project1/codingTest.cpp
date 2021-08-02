#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> input;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		input.push_back(x);
	}
	sort(input.begin(), input.end());		// �Է¹��� ���� �������� ����
	int target = 1;				// ó���� 1�� �Ǵ��� Ȯ�� �ؾ� �ǹǷ�
	for (auto x : input) {
		if (target < x)			// Ÿ���� x ���� ������ Ÿ���� ���� �� ���� ��
			break;
		target += x;		// target + x �� ���� �� ���� �۴ٸ� �� ������ ��� ����� ��
	}
	printf("%d", target);
}