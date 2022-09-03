#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator() (int& a, int& b) {
		return a > b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, cmp> pq;	// min heap 으로 선언해야 가격 낮은애를 제거할 수 있음
	vector<pair<int, int>> lecture;
	for (int i = 0; i < N; i++) {
		int p, d;
		cin >> p >> d;
		lecture.push_back({ d, p });
	}	// end of for 
	// 기간을 먼저 오름차순 기준으로 잡음. 마감일 개념이므로 첫날꺼를 안하고 둘째날 꺼를 2개 하는 방법이 가능하기 때문
	sort(lecture.begin(), lecture.end());

	for (int i = 0; i < N; i++) {
		int d = lecture[i].first;
		int p = lecture[i].second;

		pq.push(p);
		if (pq.size() > d) {		// 가장 작은것이 빠질것이고, 기간 순 오름차순이므로 이렇게 하면 기간을 맞출 수 있음
			pq.pop();
		}
	}	// end of for i

	int res = 0;

	while (!pq.empty()) {
		res += pq.top();
		pq.pop();
	}	// end of while

	cout << res << "\n";
	return 0;
}