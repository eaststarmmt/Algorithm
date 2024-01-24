#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
	vector<int> answer;
	for (int i = 0; i < intStrs.size(); i++) {
		string num = intStrs[i];
		int x = stoi(num.substr(s, l));

		if (x <= k) continue;
		answer.push_back(x);
	}
	return answer;
}