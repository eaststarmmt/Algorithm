#include<stdio.h>
#include<queue>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> card;	// ī�带 ������������ ����ؼ� ������ �ֱ� ���� �켱���� ť ���
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		card.push(x);
	}
	int sum = 0;
	while (card.size() != 1) {	// �������� ���ĵ� ī�幭���� �տ��� �� ������ ���� ���ϰ� ���� ���� �ٽ� �ִ´�
		int a, b;
		a = card.top();
		card.pop();
		b = card.top();
		card.pop();
		card.push(a + b);
		sum += a + b;
	}
	printf("%d\n", sum);
}