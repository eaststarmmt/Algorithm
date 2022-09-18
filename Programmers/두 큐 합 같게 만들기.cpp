#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
	int answer = 0;
	queue<long long> Q1, Q2;
	long long sum1, sum2;
	sum1 = sum2 = 0;
	for (int i = 0; i < queue1.size(); i++) {
		Q1.push(queue1[i]);
		sum1 += queue1[i];
		Q2.push(queue2[i]);
		sum2 += queue2[i];
	}   // end of for

	int N = Q1.size() * 3;  // 한쪽으로 하나 뺴고 넘어가고 반대쪽으로 하나뺴고 넘어가는 극한의 상황을 고려해서 * 3. 2배면 될줄 알았는데 반례 존재

	if ((sum1 + sum2) % 2 != 0) {
		return -1;
	}

	for (int i = 0; i < N; i++) {
		if (sum1 == sum2) {
			break;
		}
		else if (sum1 > sum2) {
			Q2.push(Q1.front());
			sum1 -= Q1.front();
			sum2 += Q1.front();
			Q1.pop();
		}
		else {
			Q1.push(Q2.front());
			sum2 -= Q2.front();
			sum1 += Q2.front();
			Q2.pop();
		}
		answer++;
	}   // end of for
	if (sum1 != sum2) {
		return -1;
	}
	return answer;
}