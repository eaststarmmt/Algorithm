#include<stdio.h>
#include<stack>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	stack<int> input;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		input.push(x);
	}
	stack<int> ngr;			// 숫자 비교하기 위한 스택
	stack<int> result;		// 결과값 저장하기 위한 스택
	ngr.push(input.top());	// 마지막에 받은 숫자는 가장 오른쪽 값이기 때문에 무조건 -1이 나옴
	input.pop();			
	result.push(-1);
	while (!input.empty()) {	// input을 하나씩 빼면서 비교할 것이므로 input이 빌때까지 무한 반복
		while(!ngr.empty()) {
			if (input.top() < ngr.top()) {	// ngr top에 있는 값이 가장 크면 오큰수 result로 push
				result.push(ngr.top());		
				ngr.push(input.top());		// 지금 비교한 input은 다음 숫자의 오큰수가 될 수도 있으므로 ngr에 푸쉬
				input.pop();			// input에서는 비교가 끝났으니 pop
				break;
			}
			else {
				ngr.pop();		// 오큰수가 아니므로 다음 ngr 스택의 값과 비교하기 위해 pop
			}
		}
		if (ngr.empty()) {		// ngr 스택에 모든 값이 오큰수가 아닌 경우 -1 출력 해야됨
			result.push(-1);
			ngr.push(input.top());	// 오큰수는 없지만 이 숫자가 다음 숫자의 오큰수가 될수도 있으므로 ngr에 push
			input.pop();
		}
	}
	while (!result.empty()) {
		printf("%d ", result.top());
		result.pop();
	}
}