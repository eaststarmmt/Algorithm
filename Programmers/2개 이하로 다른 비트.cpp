#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] % 2 == 0) {   // 짝수는 1의 자리가 무조건 0이기 때문에 1을 더하면 됨
			answer.push_back(numbers[i] + 1);
		}
		else {
			long long check = 1;
			while (true) {
				if ((numbers[i] & check) == 0) {
					check >>= 1;
					answer.push_back(numbers[i] + check);   // 오른쪽부터 가장 마지막에 나온 1 자리에 1을 더하면 한자리만 다른 비트를 가진 숫자를 만들 수 있음
					break;
				}
				check <<= 1;
			}   // end of while
		}
	}   // end of for
	return answer;
}