#include <string>
#include <vector>

using namespace std;

int visited[100004];

vector<int> solution(vector<int> arr, int k) {
	vector<int> answer;

	for (int x : arr) {
		if (visited[x]) continue;

		visited[x] = 1;
		answer.push_back(x);
	}

	answer.resize(k, -1);
	return answer;
}