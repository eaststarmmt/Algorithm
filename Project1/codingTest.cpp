#include<stdio.h>
#include<queue>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> card;	// 카드를 오름차순으로 계속해서 정리해 주기 위해 우선순위 큐 사용
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		card.push(x);
	}
	int sum = 0;
	while (card.size() != 1) {	// 오름차순 정렬된 카드묶음을 앞에서 두 묶음씩 빼서 더하고 더한 것을 다시 넣는다
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