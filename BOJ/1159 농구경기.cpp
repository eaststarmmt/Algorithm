#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int counting[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	string res;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		counting[s[0] - 'a']++;
	}
	bool flag = false;
	for (int i = 0; i < 26; i++) {
		if (counting[i] >= 5) {
			res += i + 'a';
		}
	}
	if (res.size() == 0) {
		cout << "PREDAJA";
	}
	else {
		cout << res;
	}
	cout << "\n";
}