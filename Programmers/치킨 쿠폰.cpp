#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
	int answer = 0;

	while (chicken >= 10) {
		int temp = chicken / 10;
		answer += temp;
		chicken = chicken % 10 + temp;
	}

	return answer;
}