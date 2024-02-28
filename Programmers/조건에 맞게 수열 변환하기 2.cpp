#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
	int answer = 0;
	vector<int> temp;

	while (true) {
		temp.clear();
		int cnt = 0;
		for (int i = 0; i < arr.size(); i++) {
			int x = arr[i];
			if (x >= 50 && x % 2 == 0) {
				x /= 2;
			}
			else if (x < 50 && x % 2 == 1) {
				x = x * 2 + 1;
			}
			else cnt++;
			temp.push_back(x);
		}
		if (cnt == arr.size()) break;
		arr = temp;
		answer++;
	}   // end of while
	return answer;
}