#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
	vector<int> answer;
	for (int x : numlist) {
		if (x % n) continue;
		answer.push_back(x);
	}
	return answer;
}