#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		int row = arr1[i] | arr2[i];
		string r;
		int bit = 1 << n;
		for (int j = 0; j < n; j++) {
			bit >>= 1;
			if (bit & row) {
				r += "#";
			}
			else {
				r += " ";
			}
		}   // end of for j
		answer.push_back(r);
	}   // end of for i
	return answer;
}