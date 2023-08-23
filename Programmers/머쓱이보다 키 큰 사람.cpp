#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
	int answer = 0;
	for (int x : array) {
		if (x > height) answer++;
	}
	return answer;
}