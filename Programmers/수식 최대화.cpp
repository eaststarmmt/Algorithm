#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

char sequence[] = { '*', '+', '-' };

long long solution(string expression) {
	long long answer = 0;
	queue<long long> operand;
	queue<char> oper;
	string num = "";
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] >= '0' && expression[i] <= '9') {    // 숫자면 계속 더하기
			num += expression[i];
		}
		else {    // 연산자가 나왔을 때
			oper.push(expression[i]);  // 큐에 연산자 넣기
			operand.push(stoll(num));    // 숫자도 끝났으므로 큐에 넣고 초기화
			num = "";
		}
	}
	operand.push(stoi(num));    // 여기까지 숫자랑 연산자 분해

	do {
		queue<long long> operand_copy = operand;  // 다음 우선순위에도 또 사용해야 하기 때문에 복사본 만들기
		queue<char> oper_copy = oper;
		for (int i = 0; i < 3; i++) {     // 연산자 별로 하나씩 계산하기
			long long num1 = operand_copy.front();
			long long num2;
			operand_copy.pop();
			bool continuous = false;
			int size = operand_copy.size();
			for (int j = 0; j < size; j++) {
				num2 = operand_copy.front();
				operand_copy.pop();
				if (sequence[i] == oper_copy.front()) {    // 계산 하려는 연산자가 맞는 경우
					if (sequence[i] == '*') {
						num1 *= num2;
					}
					else if (sequence[i] == '+') {
						num1 += num2;
					}
					else if (sequence[i] == '-') {
						num1 -= num2;
					}
					oper_copy.pop();    // 지금 연산을 했으므로 제거
				}
				else {      // 계산 안하는 경우
					operand_copy.push(num1);
					num1 = num2;    // 이전까지 계산한거 push하고 num2 값 num1로 옮기기
					oper_copy.push(oper_copy.front());  // 현재 연산자 맨 뒤로 보내기                    
					oper_copy.pop();
				}

			}
			operand_copy.push(num1);    // 마지막 값 들어갈 수 있게 push
			if (operand_copy.size() == 1) {  // 계산이 다 끝났을 때
				answer = abs(num1) > answer ? abs(num1) : answer;
			}
		}

	} while (next_permutation(sequence, sequence + 3));

	return answer;
}