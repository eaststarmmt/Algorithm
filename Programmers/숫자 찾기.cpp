#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int num, int k) {
	int answer = 0;
	string s = to_string(num);
	answer = s.find(to_string(k)) == string::npos ? -1 : s.find(to_string(k)) + 1;
	return answer;
}