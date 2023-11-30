#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr, int idx) {
	int answer = find(arr.begin() + idx, arr.end(), 1) - arr.begin();
	answer = answer == arr.size() ? -1 : answer;
	return answer;
}