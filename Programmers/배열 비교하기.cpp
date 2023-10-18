#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
	int answer = arr1.size() > arr2.size() ? 1 : (arr1.size() == arr2.size() ? 0 : -1);
	if (!answer) {
		int a = 0;
		int b = 0;
		for (int x : arr1) {
			a += x;
		}
		for (int x : arr2) {
			b += x;
		}
		answer = a > b ? 1 : (a == b ? 0 : -1);
	}
	return answer;
}