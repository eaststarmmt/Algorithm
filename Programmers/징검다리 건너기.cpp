#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int>& stones, int k) {
	int left = 0;
	int right = *max_element(stones.begin(), stones.end());
	int res = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		int max_cnt = 0;
		for (int i = 0; i < stones.size(); i++) {    // 연속으로 0된 구간 찾기
			if (stones[i] - mid < 0) {   // 0이 된건 건넜다는 뜻이라 카운팅 하지 않음
				cnt++;
			}
			else {
				max_cnt = max(cnt, max_cnt);
				cnt = 0;
			}
		}   // end of for
		max_cnt = max(cnt, max_cnt);    // 위의 반복문에서 마지막에 최댓값 갱신이 안되는 경우가 있을 수 있음
		if (max_cnt >= k) {      // 음수인 것만 카운팅함. 즉 가라앉은 돌만 카운팅. k가 3일때 3개가 카운팅 됐으면 돌 3개가 가라앉아서 못뜀
			right = mid - 1;
		}
		else {
			left = mid + 1;
			res = max(res, mid);
		}
	}   // end of while
	return res;
}

int solution(vector<int> stones, int k) {
	int answer = 0;
	answer = binary_search(stones, k);
	return answer;
}