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
	stack<int> ngr;			// ���� ���ϱ� ���� ����
	stack<int> result;		// ����� �����ϱ� ���� ����
	ngr.push(input.top());	// �������� ���� ���ڴ� ���� ������ ���̱� ������ ������ -1�� ����
	input.pop();			
	result.push(-1);
	while (!input.empty()) {	// input�� �ϳ��� ���鼭 ���� ���̹Ƿ� input�� �������� ���� �ݺ�
		while(!ngr.empty()) {
			if (input.top() < ngr.top()) {	// ngr top�� �ִ� ���� ���� ũ�� ��ū�� result�� push
				result.push(ngr.top());		
				ngr.push(input.top());		// ���� ���� input�� ���� ������ ��ū���� �� ���� �����Ƿ� ngr�� Ǫ��
				input.pop();			// input������ �񱳰� �������� pop
				break;
			}
			else {
				ngr.pop();		// ��ū���� �ƴϹǷ� ���� ngr ������ ���� ���ϱ� ���� pop
			}
		}
		if (ngr.empty()) {		// ngr ���ÿ� ��� ���� ��ū���� �ƴ� ��� -1 ��� �ؾߵ�
			result.push(-1);
			ngr.push(input.top());	// ��ū���� ������ �� ���ڰ� ���� ������ ��ū���� �ɼ��� �����Ƿ� ngr�� push
			input.pop();
		}
	}
	while (!result.empty()) {
		printf("%d ", result.top());
		result.pop();
	}
}