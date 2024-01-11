#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
	int answer = 0;
	int x = a;
	for (bool b : included) {
		if (b) answer += x;
		x += d;
	}
	return answer;
}