#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int idx = -1;   // max값 인덱스
	for (int i = 0; i < number.size() - k; i++) {    // 총 구해야 되는 글자의 길이
		char max = '0';
		for (int j = idx + 1; j <= k + i; j++) {    // k + i 는 결국 총 길이라는 것을 이용
			if (number[j] > max) {
				max = number[j];
				idx = j;
			}
		}   // end of for j
		answer += max;
	}   // end of for i
	return answer;
}