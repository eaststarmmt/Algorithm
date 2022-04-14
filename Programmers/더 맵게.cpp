#include <string>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		return a > b;     // priority_queue는 반대로 잡아야 됨
	}
};

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, cmp> food(scoville.begin(), scoville.end()); // min heap 
	if (scoville.size() == 0)
		return answer;

	while (food.top() < K) {     // 최소값이 K 이상이 될때까지 반복
		if (food.size() == 1) {  // 음식이 한 개 남은 경우는 섞지 못함
			answer = -1;
			break;
		}
		int min = food.top();
		food.pop();
		int sec_min = food.top();
		food.pop();
		int mix = min + sec_min * 2;
		food.push(mix);
		answer++;
	}

	return answer;
}