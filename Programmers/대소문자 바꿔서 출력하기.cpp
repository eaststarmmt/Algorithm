#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str, s;
	cin >> str;

	for (char c : str) {
		if (isupper(c)) s += tolower(c);
		else s += toupper(c);
	}

	cout << s << '\n';
	return 0;
}