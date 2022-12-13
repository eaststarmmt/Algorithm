#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	priority_queue<int, vector<int>> pq(works.begin(), works.end());

	while (n) {
		int x = pq.top();
		pq.pop();

		if (pq.empty()) {    // 일 한개만 남은 경우
			if (x > n)   // 남은 일이 시간 보다 많은 경우만 저장하고 아닌 경우 0이므로 없앰
				pq.push(x - n);
			break;
		}
		else {
			int dif = x - pq.top();
			if (dif == 0) {      // 남은 일의 양이 top가 같은 경우 -1
				x--;
				n--;
				if (x == 0) continue;    // 다 했으면 넣지 않음
			}
			else if (dif <= n) {   // 남은 일이 n 보다 작거나 같은 경우
				x -= dif;
				n -= dif;
			}
			else if (dif > n) {    // 남은 일이 n보다 큰 경우
				x -= n;
				n = 0;
			}
			pq.push(x);
		}
	}   // end of while

	while (!pq.empty()) {
		int x = pq.top();
		pq.pop();
		answer += (long long)x * x;
	}

	return answer;
}