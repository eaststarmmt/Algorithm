#include<stdio.h>
#include<queue>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int> positive;	// ������������ �� �ޱ�
	priority_queue<int, vector<int>, greater<int>> negative;	// ������������ �� �ޱ�
	int result = 0;
	bool zero = false;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x < 0) negative.push(x);
		else if (x > 1) positive.push(x);
		else if (x == 1) result++;	// 1�� ���ϴµ� ���� �����̹Ƿ� �׳� ���ع���
		else if (x == 0) zero = true;	// ���� ������ �� ���� ������ �� ���ؼ� ���ֱ� ����
	}
	if (positive.size() % 2 == 1) positive.push(1);
	if (negative.size() % 2 == 1) {
		if (zero) negative.push(0);
		else negative.push(1);
	}
	while (!positive.empty()) {	
		int a, b;		// �� ���� ���ؼ� ���ϱ�
		a = positive.top();
		positive.pop();
		b = positive.top();
		positive.pop();
		result += a * b;
		
	}

	while (!negative.empty()) {
		int a, b;
		a = negative.top();
		negative.pop();
		b = negative.top();
		negative.pop();
		result += a * b;
	}
	printf("%d\n", result);
}