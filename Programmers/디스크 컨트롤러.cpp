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
		if (i < size && now >= jobs[i][0]) {   // ���� �ð� ���� ��û ���� �۾��� �켱���� ť�� ����
			pq.push({ jobs[i][0], jobs[i][1] });
			i++;
			continue;
		}
		if (!pq.empty()) {
			now += pq.top().time;   // ���� �ð����� �۾��� �ɸ��� �ð���ŭ ���
			answer += now - pq.top().req;   // ���� �ð����� �۾� ��û �ð��� ���� ��û���� ������� �ð��� ����
			pq.pop();           // �ϳ� �۾��ϰ� �켱����ť �����ؾߵ�
		}
		else {
			now = jobs[i][0];   // �̹� �տ��� ���� �ð� ������ �۾��� �� �־��µ� �켱����ť�� ����ִ� ��Ȳ�� ������ ���� i ���� size��ŭ ���������� else�� �ȳѾ���� �̹� while���� ����������
		}

	}   // end of while

	return answer / size;
}