#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
	int answer = 0;
	while (storey) {
		int mod = storey % 10;
		int moc = storey / 10;
		if (mod < 5) {
			answer += mod;
			storey -= mod;

		}
		else if (mod > 5) {
			answer += 10 - mod;
			storey += 10 - mod;
		}
		else {
			if (moc % 10 >= 5) {
				answer += 10 - mod;
				storey += 10 - mod;
			}
			else {
				answer += mod;
				storey -= mod;
			}
		}
		storey /= 10;
	}   // end of while
	return answer;
}