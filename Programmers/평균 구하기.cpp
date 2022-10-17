#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
	double answer = 0;
	for (double x : arr) {
		answer += x;
	}
	answer /= arr.size();
	return answer;
}