#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[100];

int select_card(vector<int>& cards) {
	int idx = 0;

	for (int i = 0; i < cards.size(); i++) {
		if (!visited[i]) {
			idx = i;
			break;
		}
	}

	int res = 0;

	while (true) {
		if (visited[idx]) break;
		visited[idx] = true;
		res++;
		idx = cards[idx] - 1;
	}   // end of while

	return res;
}

int solution(vector<int> cards) {
	int answer = 0;
	vector<int> score;

	while (true) {
		int x = select_card(cards);
		score.push_back(x);
		if (!x) break;
	}

	sort(score.begin(), score.end(), greater<int>());
	answer = score[0] * score[1];
	return answer;
}