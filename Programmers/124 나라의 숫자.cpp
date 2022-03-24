#include <string>
#include <vector>

using namespace std;
char num[] = { '4', '1', '2' };   // ���� �������� �� 4�� ���� �ż� 0���� 4�� ��

string solution(int n) {
	string answer = "";
	while (n > 0) {
		int remainder = n % 3;
		n /= 3;
		if (remainder == 0) // ���ڰ� 0���Ͱ� �ƴ� 1���� �����ؼ� ����� ����
			n--;
		answer = num[remainder] + answer;
	}
	return answer;
}