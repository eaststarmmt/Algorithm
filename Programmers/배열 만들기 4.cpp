#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> stk;
	for (int i = 0; i < arr.size(); i++) {
		int x = arr[i];
		while (!stk.empty() && x <= stk[stk.size() - 1]) {
			stk.pop_back();
		}   // end of while
		stk.push_back(x);
	}
	return stk;
}