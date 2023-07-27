#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;

bool cmp(int a, int b) {
	int sub_a = abs(N - a);
	int sub_b = abs(N - b);

	if (sub_a == sub_b) {
		return a > b;
	}
	return sub_a < sub_b;
}

vector<int> solution(vector<int> numlist, int n) {
	N = n;
	sort(numlist.begin(), numlist.end(), cmp);
	vector<int> answer(numlist.begin(), numlist.end());

	return answer;
}