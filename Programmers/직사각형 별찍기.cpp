#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	int b;
	cin >> a >> b;
	string s;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			s += "*";
		}
		s += "\n";
	}
	cout << s;
	return 0;
}