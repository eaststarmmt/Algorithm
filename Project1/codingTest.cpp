#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test = 1; test <= T; test++) {
		string input, input2;
		cin >> input;
		input2 = input;
		int result = 0;
		int lcut = 0;
		int rcut = 0;
		for (int i = 0, j = input.size() - 1; i < j; i++, j--) {
			if (input[i] != input[j]) {

				if (input[i + 1] == input[j]) {
					input.erase(i, 1);
					j--;
					lcut++;
					
				}
				/*else if (input[i] == input[j - 1]) {
					input.erase(j, 1);
					j--;
					cut++;
				}*/
				else lcut = 2;
			}
			if (lcut == 2) break;
		}
		for (int i = 0, j = input2.size() - 1; i < j; i++, j--) {

			if (input2[i] != input2[j]) {
			
				if (input2[i] == input2[j - 1]) {
					input2.erase(j, 1);
					j--;
					rcut++;
				}
				else rcut = 2;	
			}
			if (rcut == 2) break;
		}

		cout << min(lcut, rcut) << "\n";
	}

}