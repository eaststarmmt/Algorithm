#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
	string a_str = to_string(a) + to_string(b);
	string b_str = to_string(b) + to_string(a);

	int answer = a_str > b_str ? stoi(a_str) : stoi(b_str);
	return answer;
}