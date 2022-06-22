#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Info {
	int req, time;
};

struct cmp {
	bool operator() (Info& a, Info& b) {
		return a.time > b.time;
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	sort(jobs.begin(), jobs.end());
	priority_queue<Info, vector<Info>, cmp> pq;
	int now = 0;
	int i = 0;
	int size = jobs.size();
	while (i < size || !pq.empty()) {
		if (i < size && now >= jobs[i][0]) {   // 현재 시간 전에 요청 들어온 작업들 우선순위 큐에 저장
			pq.push({ jobs[i][0], jobs[i][1] });
			i++;
			continue;
		}
		if (!pq.empty()) {
			now += pq.top().time;   // 현재 시간부터 작업에 걸리는 시간만큼 경과
			answer += now - pq.top().req;   // 현재 시간에서 작업 요청 시간을 빼면 요청부터 종료까지 시간값 나옴
			pq.pop();           // 하나 작업하고 우선순위큐 갱신해야됨
		}
		else {
			now = jobs[i][0];   // 이미 앞에서 현재 시간 이전의 작업은 다 넣었는데 우선순위큐가 비어있는 상황은 나오지 않음 i 값이 size만큼 증가했으면 else로 안넘어오고 이미 while문이 끝났을것임
		}

	}   // end of while

	return answer / size;
}