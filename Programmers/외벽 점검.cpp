#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int weak_size, answer;
bool selected[15];

void permutation(vector<int>& worker, vector<int>& weak, vector<int>& dist) {
	if (worker.size() == dist.size()) {
		for (int start = 0; start < weak_size; start++) {
			int idx = 1;    // 투입된 일꾼 수
			int cnt = 0;    // 확인한 지역 수
			int end_pos = weak[start] + worker[idx - 1];  // 현재 친구가 갈 수 있는 최대 거리
			for (int pos = start; pos < start + weak_size; pos++) {  // 탐색한 짐점
				if (end_pos >= weak[pos]) { // 사거리 내에 들어오면 카운팅. 만약 다 확인했으면 최댓값 갱신
					if (++cnt == weak_size) {
						answer = min(idx, answer);
						break;
					}
				}
				else {
					idx++;
					if (idx > dist.size()) { // 전체 일꾼보다 많으면 종료
						break;
					}
					if (++cnt == weak_size) {
						answer = min(idx, answer);
						break;
					}
					end_pos = weak[pos] + worker[idx - 1];    // 현재 위치 + 다음 일꾼의 이동 가능 거리
				}
			}   // end of for end

		}   // end of for start
		return;
	}   // end of if

	for (int i = 0; i < dist.size(); i++) {
		if (selected[i]) continue;
		worker.push_back(dist[i]);
		selected[i] = true;
		permutation(worker, weak, dist);
		worker.pop_back();
		selected[i] = false;
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	weak_size = weak.size();
	answer = dist.size() + 1;
	for (int i = 0; i < weak_size; i++) { // 회전 문제이므로 두바퀴를 만들어서 반시계방향을 고려할 필요 없게 만듬
		weak.push_back(n + weak[i]);
	}   // end of for weak
	vector<int> worker;
	permutation(worker, weak, dist);

	if (answer > dist.size()) {
		answer = -1;
	}

	return answer;
}