#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
	int sum = 0;
	int mul = 1;

	for (int x : num_list) {
		mul *= x;
		sum += x;
	}   // end of for

	int answer = sum * sum > mul ? 1 : 0;
	return answer;
}