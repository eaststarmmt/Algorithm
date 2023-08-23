#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
	vector<int> answer(2);
	for (int x : num_list) {
		if (x % 2 == 0) answer[0]++;
		else answer[1]++;
	}
	return answer;
}