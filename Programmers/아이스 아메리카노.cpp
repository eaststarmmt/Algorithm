#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
	vector<int> answer = { money / 5500, money % 5500 };
	return answer;
}