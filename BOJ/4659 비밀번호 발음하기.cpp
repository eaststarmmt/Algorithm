#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cnt[30];
bool vowel_check(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	while (cin >> s) {
		if (s == "end") {
			break;
		}
		memset(cnt, 0, sizeof(cnt));
		int vowel = 0;
		int consonant = 0;
		bool flag = true;
		for (int i = 0; i < s.size(); i++) {
			cnt[s[i] - 'a']++;
			if (vowel_check(s[i])) {
				vowel++;
				consonant = 0;
			}
			else {
				consonant++;
				vowel = 0;
			}

			if (vowel == 3 || consonant == 3) {	// 세글자 연속인지 확인
				flag = false;
			}
			if (i > 0 && (s[i] == s[i - 1]) && (s[i] != 'e' && s[i] != 'o')) {	// i나 o 가 아닌데 같은 글자 연속으로 나온 경우 
				flag = false;
			}

		}	// end of for i
		if (cnt['a' - 'a'] == 0 && cnt['e' - 'a'] == 0 && cnt['i' - 'a'] == 0 && cnt['o' - 'a'] == 0 && cnt['u' - 'a'] == 0) {
			flag = false;
		}

		if (!flag) {
			cout << "<" << s << "> is not acceptable.\n";
		}
		else {
			cout << "<" << s << "> is acceptable.\n";
		}
	}	// end of while

	return 0;
}