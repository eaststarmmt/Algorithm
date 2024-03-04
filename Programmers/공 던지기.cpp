#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
	int answer = 0;
	for (int i = 0, idx = 0; i < k; i++, idx = (idx + 2) % numbers.size()) {
		answer = numbers[idx];
	}
	return answer;
}