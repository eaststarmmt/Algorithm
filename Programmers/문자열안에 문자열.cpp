#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	answer = str1.find(str2) != string::npos ? 1 : 2;
	return answer;
}