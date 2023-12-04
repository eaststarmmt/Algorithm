#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
	int a = box[0] / n;
	int b = box[1] / n;
	int c = box[2] / n;
	int answer = a * b * c;
	return answer;
}