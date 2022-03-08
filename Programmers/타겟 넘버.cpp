#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Info {   // numbers의 인덱스, 현재까지의 합, 계산한 숫자 개수
	int index, sum, cnt;
};
int answer;
void bfs(vector<int> numbers, int target) {
	queue<Info> Q;
	Q.push({ 0, numbers[0], 1 }); // +와 - 각각 잡고 시작
	Q.push({ 0, -numbers[0], 1 });
	int size = numbers.size();
	while (!Q.empty()) {
		int index = Q.front().index;
		int sum = Q.front().sum;
		int cnt = Q.front().cnt;
		Q.pop();
		if (cnt == size && sum == target) answer++;  // 모든 숫자를 다 계산 했을 때 target과 일치하면 카운팅
		if (index == size) return;   // 크기 넘어가면 종료

		Q.push({ index + 1, sum + numbers[index + 1], cnt + 1 });
		Q.push({ index + 1, sum - numbers[index + 1], cnt + 1 });

	}
}

int solution(vector<int> numbers, int target) {
	bfs(numbers, target);
	return answer;
}