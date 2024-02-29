#include <string>
#include <vector>

using namespace std;

int cnt[10004];

vector<int> solution(int n) {
	vector<int> answer;
	int i = 2;
	int N = n;
	while (i <= N) {
		if (n % i) {
			i++;
			continue;
		}
		if (!cnt[i]++) {
			answer.push_back(i);
		}
		n /= i;
	}
	return answer;
}