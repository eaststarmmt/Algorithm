#include <string>
#include <vector>

using namespace std;

int get_seven(int x) {
	int res = 0;

	while (x) {
		int mod = x % 10;
		if (mod == 7) res++;

		x /= 10;
	}
	return res;
}

int solution(vector<int> array) {
	int answer = 0;
	for (int x : array) {
		answer += get_seven(x);
	}   // end of for
	return answer;
}