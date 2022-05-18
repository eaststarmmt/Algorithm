#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string vowel = "AEIOU";
vector<string> dic;
void comb(int cnt, int target, string s = "") {
	if (cnt == target) {
		dic.push_back(s);
		return;
	}

	for (int i = 0; i < 5; i++) {
		comb(cnt + 1, target, s + vowel[i]);
	}
}

int solution(string word) {
	int answer = 0;
	for (int i = 1; i <= 5; i++) {   // 해당 길이만큼 단어 뽑아내기
		comb(0, i);
	}
	sort(dic.begin(), dic.end());   // 사전순 정렬
	answer = find(dic.begin(), dic.end(), word) - dic.begin() + 1;
	return answer;
}