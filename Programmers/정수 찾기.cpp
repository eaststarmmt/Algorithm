#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> num_list, int n) {
	int answer = find(num_list.begin(), num_list.end(), n) == num_list.end() ? 0 : 1;
	return answer;
}