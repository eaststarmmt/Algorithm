#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
	int answer = 0;
	for (string s : babbling) {
		int flag = 0;
		for (int i = 0; i < s.size();) {
			if (!s.compare(i, 3, "aya") && flag != 1) {
				i += 3;
				flag = 1;
			}
			else if (!s.compare(i, 2, "ye") && flag != 2) {
				i += 2;
				flag = 2;
			}
			else if (!s.compare(i, 3, "woo") && flag != 3) {
				i += 3;
				flag = 3;
			}
			else if (!s.compare(i, 2, "ma") && flag != 4) {
				i += 2;
				flag = 4;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) answer++;
	}
	return answer;
}