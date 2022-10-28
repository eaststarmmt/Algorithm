#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	bool answer = true;
	int sum = 0;
	int temp = x;
	while (temp) {
		sum += temp % 10;
		temp /= 10;
	}   // end of while
	answer = x % sum == 0 ? true : false;
	return answer;
}