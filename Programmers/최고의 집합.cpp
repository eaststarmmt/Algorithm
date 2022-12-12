#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;

	if (n > s) return vector<int> {-1};

	while (true) {
		if (n == 0) break;
		answer.push_back(s / n);
		s -= s / n;
		n--;
	}   // end of while
	return answer;
}