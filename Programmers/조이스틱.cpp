#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string name) {
	int answer = 0;
	int len = name.size();
	int mid = len / 2;
	int front = 0;      // ������ ���� �Ÿ�
	int front_to_mid = 0;   // �տ��� �߰����� �Ÿ�
	int end = 0;        // �ڷκ��� �Ÿ�
	int end_to_mid = 0; // �߰����� �ڱ��� �Ÿ�
	// �߰��� �������� ���ʰ� ���� ���������� A�� �ƴ� �κ� Ȯ���ؾ� ��
	for (int i = 0; i < len; i++) {
		answer += name[i] - 'A' <= 13 ? name[i] - 'A' : 'Z' - name[i] + 1;    // ���ĺ� �ٲٴ� Ƚ��
		if (name[i] != 'A') {    // �տ��������� �Ÿ� ���
			front = i;
			if (i <= mid)
				front_to_mid = i;   // �߰� ���̸� �Ÿ� ����
		}
		if (name[len - i] != 'A') {    // front�� ����
			end = i;
			if (len - i > mid)
				end_to_mid = i;
		}
	}
	answer += min(min(front, end), min(2 * front_to_mid + end_to_mid, 2 * end_to_mid + front_to_mid));
	return answer;
}