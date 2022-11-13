#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
	int answer = 45;
	for (int x : numbers) {
		answer -= x;
	}   // end of for
	return answer;
}