#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
	int answer = 0;
	int dif = common[1] - common[0];

	int mod = !common[0] ? 1e9 : common[1] / common[0];

	for (int i = 2; i < common.size(); i++) {
		if (dif != common[i] - common[i - 1]) {
			dif = 1e9;
			break;
		}
	}

	answer = dif == 1e9 ? common[common.size() - 1] * mod : common[common.size() - 1] + dif;
	return answer;
}