#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// �ð��� Ÿ������ ��Ƽ� ��� �ɻ���� �ش� �ð� ���� �ɻ��� �� �ִ� ��� �� ���� �� �� �ð� �ּҰ����� �̾Ƴ��� ���
long long binarySearch(int n, vector<int> times) {
	long long start = 1;
	long long end = (long long)n * (*max_element(times.begin(), times.end()));    // �־��� ���
	long long res = end;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < times.size(); i++) {
			sum += mid / times[i];  // �ð� / �ɻ��ϴµ� �ɸ��� �ð� = �ش� �ð����� �ɻ��� �� �ִ� ��� ��
		}   // end of sum
		if (sum >= n) {  // �˻縦 ��� �� �� �ִ� ���. �� �߿� �ּҰ� �̾Ƴ��ߵ�
			res = mid < res ? mid : res;
			end = mid - 1;
		}
		else {  // �ð��� ���ڶ� ���. �ð� �÷���� ��
			start = mid + 1;
		}
	}
	return res;
}

long long solution(int n, vector<int> times) {
	long long answer = 0;
	answer = binarySearch(n, times);
	return answer;
}