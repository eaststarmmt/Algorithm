#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	auto i = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
	answer = "김서방은 " + to_string(i) + "에 있다";
	return answer;
}