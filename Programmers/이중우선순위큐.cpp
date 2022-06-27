#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct cmp {
	bool operator() (int& a, int& b) {
		return a > b;
	}
};

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	int cnt = 0;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, cmp> minHeap;

	for (int i = 0; i < operations.size(); i++) {
		if (operations[i].substr(0, 1) == "I") {
			maxHeap.push(stoi(operations[i].substr(2)));
			minHeap.push(stoi(operations[i].substr(2)));
			cnt++;
		}
		else if (cnt == 0) {   // 큐 비었을 때 무시
			continue;
		}
		else {
			cnt--;
			if (cnt == 0) {
				maxHeap = priority_queue<int>();        // 큐가 비었을때 같이 비워주지 않으면 결과에 영향 받음
				minHeap = priority_queue<int, vector<int>, cmp>();
			}
			else if (operations[i].substr(2, 1) == "-") {
				minHeap.pop();
			}
			else {
				maxHeap.pop();
			}
		}
	}   // end of for
	if (cnt == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(maxHeap.top());
		answer.push_back(minHeap.top());
	}
	return answer;
}