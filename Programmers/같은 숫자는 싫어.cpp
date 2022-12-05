#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer = { arr[0] };

	for (int i = 1; i < arr.size(); i++) {
		if (answer.back() != arr[i]) {
			answer.push_back(arr[i]);
		}
	}   // end of for

	return answer;
}