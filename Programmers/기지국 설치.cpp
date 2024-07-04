#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int get_cnt(int lo, int hi, int w) {
	int res = 0;
	int cnt = (hi - lo + 1) / (2 * w + 1);
	if (cnt < 0) return 0;
	if ((hi - lo + 1) % (2 * w + 1)) cnt++;
	res = cnt;
	return res;
}

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int lo = 1;
	int hi;

	for (int mid : stations) {
		hi = mid - w - 1;
		int cnt = hi < lo || lo > hi ? 0 : get_cnt(lo, hi, w);
		answer += cnt;
		lo = mid + w + 1;
	}   // end of for stations
	if (lo <= n) {
		int cnt = get_cnt(lo, n, w);
		answer += max(0, cnt);
	}
	return answer;
}