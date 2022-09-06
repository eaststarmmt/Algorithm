#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp_pq {
	bool operator()(int& A, int& B) {
		return A > B;
	}
};

bool cmp(pair<int, int>& A, pair<int, int>& B) {
	return A.first < B.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> prob;
	for (int i = 0; i < N; i++) {
		int d, num;
		cin >> d >> num;
		prob.push_back({ d, num });
	}	// end of for

	sort(prob.begin(), prob.end(), cmp);

	priority_queue<int, vector<int>, cmp_pq> pq;
	int res = 0;
	for (int i = 0; i < N; i++) {
		int due = prob[i].first;
		int num = prob[i].second;
		res += num;
		pq.push(num);
		while (pq.size() > due) {	// 현재 마감일보다 pq 크기가 더 크면 빼줘야 됨. min heap이므로 그냥 위에서 개수 맞을때까지 빼면 됨
			res -= pq.top();
			pq.pop();
		}	// end of while
	}	// end of for

	cout << res << "\n";
	return 0;
}