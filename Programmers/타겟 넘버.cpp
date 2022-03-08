#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Info {   // numbers�� �ε���, ��������� ��, ����� ���� ����
	int index, sum, cnt;
};
int answer;
void bfs(vector<int> numbers, int target) {
	queue<Info> Q;
	Q.push({ 0, numbers[0], 1 }); // +�� - ���� ��� ����
	Q.push({ 0, -numbers[0], 1 });
	int size = numbers.size();
	while (!Q.empty()) {
		int index = Q.front().index;
		int sum = Q.front().sum;
		int cnt = Q.front().cnt;
		Q.pop();
		if (cnt == size && sum == target) answer++;  // ��� ���ڸ� �� ��� ���� �� target�� ��ġ�ϸ� ī����
		if (index == size) return;   // ũ�� �Ѿ�� ����

		Q.push({ index + 1, sum + numbers[index + 1], cnt + 1 });
		Q.push({ index + 1, sum - numbers[index + 1], cnt + 1 });

	}
}

int solution(vector<int> numbers, int target) {
	bfs(numbers, target);
	return answer;
}