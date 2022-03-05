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
		if (expression[i] >= '0' && expression[i] <= '9') {    // ���ڸ� ��� ���ϱ�
			num += expression[i];
		}
		else {    // �����ڰ� ������ ��
			oper.push(expression[i]);  // ť�� ������ �ֱ�
			operand.push(stoll(num));    // ���ڵ� �������Ƿ� ť�� �ְ� �ʱ�ȭ
			num = "";
		}
	}
	operand.push(stoi(num));    // ������� ���ڶ� ������ ����

	do {
		queue<long long> operand_copy = operand;  // ���� �켱�������� �� ����ؾ� �ϱ� ������ ���纻 �����
		queue<char> oper_copy = oper;
		for (int i = 0; i < 3; i++) {     // ������ ���� �ϳ��� ����ϱ�
			long long num1 = operand_copy.front();
			long long num2;
			operand_copy.pop();
			bool continuous = false;
			int size = operand_copy.size();
			for (int j = 0; j < size; j++) {
				num2 = operand_copy.front();
				operand_copy.pop();
				if (sequence[i] == oper_copy.front()) {    // ��� �Ϸ��� �����ڰ� �´� ���
					if (sequence[i] == '*') {
						num1 *= num2;
					}
					else if (sequence[i] == '+') {
						num1 += num2;
					}
					else if (sequence[i] == '-') {
						num1 -= num2;
					}
					oper_copy.pop();    // ���� ������ �����Ƿ� ����
				}
				else {      // ��� ���ϴ� ���
					operand_copy.push(num1);
					num1 = num2;    // �������� ����Ѱ� push�ϰ� num2 �� num1�� �ű��
					oper_copy.push(oper_copy.front());  // ���� ������ �� �ڷ� ������                    
					oper_copy.pop();
				}

			}
			operand_copy.push(num1);    // ������ �� �� �� �ְ� push
			if (operand_copy.size() == 1) {  // ����� �� ������ ��
				answer = abs(num1) > answer ? abs(num1) : answer;
			}
		}

	} while (next_permutation(sequence, sequence + 3));

	return answer;
}