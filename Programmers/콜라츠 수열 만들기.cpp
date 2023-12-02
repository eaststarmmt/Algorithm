#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer = { n };
	int x = n;
	while (x != 1) {
		if (x % 2) x = 3 * x + 1;
		else x /= 2;
		answer.push_back(x);
	}
	return answer;
}