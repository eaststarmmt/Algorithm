#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_suffix) {
	int answer = 0;
	reverse(my_string.begin(), my_string.end());
	reverse(is_suffix.begin(), is_suffix.end());

	answer = my_string.substr(0, is_suffix.size()) == is_suffix;
	return answer;
}