#include<stdio.h>
#include<queue>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int> positive;	// 내림차순으로 값 받기
	priority_queue<int, vector<int>, greater<int>> negative;	// 오름차순으로 값 받기
	int result = 0;
	bool zero = false;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x < 0) negative.push(x);
		else if (x > 1) positive.push(x);
		else if (x == 1) result++;	// 1은 곱하는데 쓰면 손해이므로 그냥 더해버림
		else if (x == 0) zero = true;	// 만약 음수가 한 개만 남았을 때 곱해서 없애기 위함
	}
	if (positive.size() % 2 == 1) positive.push(1);
	if (negative.size() % 2 == 1) {
		if (zero) negative.push(0);
		else negative.push(1);
	}
	while (!positive.empty()) {	
		int a, b;		// 두 개씩 곱해서 더하기
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