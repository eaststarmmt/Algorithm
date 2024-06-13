#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

map<char, string> m;
int T;
string s1, s2;

int dif(char c1, char c2) {
	int res = 0;

	string x = m[c1];
	string y = m[c2];

	for (int i = 0; i < x.size(); i++) {
		if (x[i] != y[i]) res++;
	}

	return res;
}

int count(string x, string y) {
	int res = 0;
	for (int i = 0; i < 5; i++) {
		res += dif(x[i], y[i]);
	} // end of for
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	m['0'] = "1110111";
	m['1'] = "0010010";
	m['2'] = "1011101";
	m['3'] = "1011011";
	m['4'] = "0111010";
	m['5'] = "1101011";
	m['6'] = "1101111";
	m['7'] = "1110010";
	m['8'] = "1111111";
	m['9'] = "1111011";
	m[' '] = "0000000";

	while (T--) {
		// 5자리 맞추기 위해 공백으로 시작
		s1 = "     ";
		s2 = "     ";
		string s;
		cin >> s;
		s1 += s;
		// 문자열 뒤에서부터 5개 저장
		s1 = s1.substr(s1.size() - 5);
		cin >> s;
		s2 += s;
		s2 = s2.substr(s2.size() - 5);

		cout << count(s1, s2) << '\n';

	}    // end of while
	return 0;
}