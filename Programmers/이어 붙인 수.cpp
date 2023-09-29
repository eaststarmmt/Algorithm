#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
	string odd, even;

	for (int x : num_list) {
		if (x % 2 == 0) even += to_string(x);
		else odd += to_string(x);
	}

	int answer = stoi(even) + stoi(odd);
	return answer;
}