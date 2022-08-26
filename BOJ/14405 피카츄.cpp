#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < s.size();) {
		if (i < s.size() - 1 && s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka") {
			i += 2;
		}
		else if (i < s.size() - 2 && s.substr(i, 3) == "chu") {
			i += 3;
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}	// end of for

	cout << "YES\n";
	return 0;
}