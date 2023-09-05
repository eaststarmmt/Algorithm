#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array) {
	int answer = 0;
	sort(array.begin(), array.end());
	answer = array[array.size() / 2];
	return answer;
}