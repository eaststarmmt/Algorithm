#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int start = 0;
	int end = people.size() - 1;
	int escape = 0;     // Ż���� ��� ��
	while (start < end) {    // �������� ����
		if (people[start] + people[end] <= limit) {  // �θ��� �� �������� ���
			answer++;
			escape += 2;
			start++;
			end--;
		}
		else {    // �� ���ſ� ������� �ٲ㼭 ���� �������� ���������� Ȯ���ϱ�
			end--;
		}
	}
	answer += people.size() - escape;   // �θ� Ż�� ���� ����� ���� ��ŭ 
	return answer;
}