#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	for (int x : arr) {
		for (int i = 0; i < x; i++) {
			answer.push_back(x);
		}
	}   // end of for arr
	return answer;
}