#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
	set<int> s;

	for (int i = 0; i < numbers.size() - 1; i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			s.insert(numbers[i] + numbers[j]);
		}
	}
	vector<int> answer(s.begin(), s.end());
	return answer;
}