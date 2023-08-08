#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
	double answer = 0;
	for (int x : numbers) {
		answer += x;
	}

	return answer / numbers.size();
}