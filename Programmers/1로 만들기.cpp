#include <string>
#include <vector>
#include <iostream>
using namespace std;

int mod_count(int x) {
	if (x == 0) return 0;
	int res = 0;

	while (x != 1) {
		if (x % 2) x--;
		if (x == 1) break;
		x /= 2;
		res++;
	}

	return res;

}

int solution(vector<int> num_list) {
	int answer = 0;
	for (int i = 0; i < num_list.size(); i++) {
		answer += mod_count(num_list[i]);
		cout << answer << endl;
	}
	return answer;
}