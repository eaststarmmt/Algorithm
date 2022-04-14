#include <string>
#include <vector>

using namespace std;
char num[] = { '4', '1', '2' };   // 나눠 떨어졌을 때 4가 들어가야 돼서 0번이 4가 됨

string solution(int n) {
	string answer = "";
	while (n > 0) {
		int remainder = n % 3;
		n /= 3;
		if (remainder == 0) // 숫자가 0부터가 아닌 1부터 시작해서 생기는 문제
			n--;
		answer = num[remainder] + answer;
	}
	return answer;
}