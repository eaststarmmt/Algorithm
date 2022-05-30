#include <string>
#include <vector>
using namespace std;
string remain = "0123456789ABCDEF";

string getSeq(int n, int num) {
	string s;
	while (num > 0) {    // 진법 변환을 위해 나머지 값만 저장
		s += remain[num % n];
		num /= n;
	}   // end of while
	num += "0";
	string result;
	for (int i = s.size() - 1; i >= 0; i--) {    // 나머지를 순서대로 넣었으므로 반대로 뒤집어야 진법에 맞는 숫자가 나옴
		result += s[i];
	}   // end of for
	return result;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	string seq = "0";
	int num = 1;
	while (seq.size() < m * t) {    // 인원수 * 개수만큼 알고 있어야 원하는 값을 뽑을 수 있음
		seq += getSeq(n, num++);
	}   // end of while

	for (int i = p - 1; i < m * t; i += m) {    // 자기 순서부터 인원수 * 개수 까지 실행
		answer += seq[i];
	}
	return answer;
}