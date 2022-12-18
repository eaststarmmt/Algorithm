#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> v;
	// 3진법 번환
	while (n) {
		v.push_back(n % 3);
		n /= 3;
	}   // end of while

	reverse(v.begin(), v.end());

	for (int i = 0, num = 1; i < v.size(); i++, num *= 3) {
		answer += v[i] * num;
	}
	return answer;
}