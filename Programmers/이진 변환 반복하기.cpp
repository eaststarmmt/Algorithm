#include <string>
#include <vector>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer(2);
	while (s.size() != 1) {  // 1 한 개 남을 때까지 실행
		string temp = "";
		for (int i = 0; i < s.size(); i++) {
			// 모든 0 제거 하면서 0 개수 카운팅
			if (s[i] == '0') {
				answer[1]++;
			}
			else {
				temp += "1";
			}

		}   // end of for
		int len = temp.size();  // 1만 남은 이진수의 길이 측정
		s = "";
		while (len > 0) {    // 0이 될때까지 계속 진행
			s += len % 2 == 0 ? '0' : '1';  // 순서 뒤집혔지만 어차피 1의 개수로 판단하기 때문에 상관 없음
			len >>= 1;
		}   // end of while
		answer[0]++;
	}   // end of while
	return answer;
}