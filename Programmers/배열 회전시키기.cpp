#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
	vector<int> answer(numbers.begin(), numbers.end());
	if (direction == "right") rotate(answer.begin(), answer.begin() + answer.size() - 1, answer.end());
	else rotate(answer.begin(), answer.begin() + 1, answer.end());
	return answer;
}