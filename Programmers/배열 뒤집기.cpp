#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
	reverse(num_list.begin(), num_list.end());
	vector<int> answer = num_list;
	return answer;
}