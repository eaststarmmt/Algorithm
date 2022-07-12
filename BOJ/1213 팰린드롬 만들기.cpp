#include<iostream>
#include<string>
using namespace std;

int cnt[200];	// 아스키 그대로 쓸거라서 안전하게 200으로 선언

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	for (char c : s) {
		cnt[c]++;
	}

	int flag = 0;
	string res;
	char mid = 0;
	for (int i = 'Z'; i >= 'A'; i--) {
		if (cnt[i]) {
			if (cnt[i] & 1) {	// 홀수인 경우
				flag++;
				mid = (char)i;
				cnt[i]--;
			}
			if (flag == 2) {
				cout << "I'm Sorry Hansoo\n";
				return 0;
			}
			for (int j = 0; j < cnt[i]; j += 2) {
				res += (char)i;
				res = (char)i + res;
			}
		}
	}
	if (mid) {
		res.insert(res.begin() + res.size() / 2, mid);
	}
	cout << res << "\n";
}