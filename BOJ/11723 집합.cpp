#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;
	int S = 0;
	for (int i = 0; i < M; i++) {
		string oper;
		int x;
		cin >> oper;

		if (oper == "add") {
			cin >> x;
			S |= 1 << x;
		}
		else if (oper == "remove") {
			cin >> x;
			S &= ~(1 << x);
		}
		else if (oper == "check") {
			cin >> x;
			int res = S & (1 << x) ? 1 : 0;
			cout << res << "\n";
		}
		else if (oper == "toggle") {
			cin >> x;
			S ^= 1 << x;
		}
		else if (oper == "all") {
			S = (1 << 21) - 1;
		}
		else if (oper == "empty") {
			S = 0;
		}
	}	// end of for

	return 0;
}