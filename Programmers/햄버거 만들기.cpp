#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
	int answer = 0;
	vector<int> hamberger;
	for (int x : ingredient) {
		int size = hamberger.size();
		if (size >= 3 && x == 1 && hamberger[size - 1] == 3 && hamberger[size - 2] == 2 && hamberger[size - 3] == 1) {   // 재료 세개 이상 있고 순서 맞는 경우  
			hamberger.pop_back();
			hamberger.pop_back();
			hamberger.pop_back();
			answer++;

		}
		else {
			hamberger.push_back(x);
		}
	}   // end of for
	return answer;
}