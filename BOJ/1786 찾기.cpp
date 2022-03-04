#include<iostream>
#include<string>
#include<vector>
using namespace std;

int pi[1000001];	// 실패함수

int main() {
	string text, pattern;
	getline(cin, text);		// 공백 포함해야 되기 때문에 getline으로 받음
	getline(cin, pattern);
	int textLen = text.length(), pattLen = pattern.length();
	// kmp 알고리즘
	for (int i = 1, j = 0; i < pattLen; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}

		if (pattern[i] == pattern[j]) pi[i] = ++j;
		else pi[i] = 0;
	}

	int cnt = 0;
	vector<int> index;

	for (int i = 0, j = 0; i < textLen; ++i) {
		while (j > 0 && text[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == pattLen - 1) {
				cnt++;
				index.push_back(i - pattLen + 2);
				j = pi[j];
			}
			else j++;
		}
	}

	printf("%d\n", cnt);
	for (auto i : index) {
		printf("%d ", i);
	}
	printf("\n");
}