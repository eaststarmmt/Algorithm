#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

bool isPossible(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t, long long mid) {
	long long gold = 0;     // 조달한 광물들 양
	long long silver = 0;
	long long goldSilver = 0;
	for (int i = 0; i < g.size(); i++) {
		long long rtt = t[i] * 2;       // 왕복 시간
		long long cnt = mid / rtt;      // 주어진 시간 / 왕복시간
		if (mid % rtt >= t[i]) cnt++;    // 나머지가 올수 있는 시간이면 카운팅. 돌아갈 필요 없으므로
		long long send = w[i] * cnt;    // 전달한 횟수 * 한번에 보낼 수 있는 최대 무게를 통해 얼마나 받았는지 체크
		gold += min((long long)g[i], send); // 최대 전달한 무게가 금의 무게보다 많으면 안됨. 최대값 더해주기
		silver += min((long long)s[i], send);
		goldSilver += min((long long)s[i] + g[i], send);   // 둘 다 가능하고 둘을 합친것의 무게까지 확인해야 됨
	}

	if (gold >= a && silver >= b && goldSilver >= a + b) return true;    // 광물을 필요한 양 이상 전달 가능하면 true
	return false;

}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
	long long start = 0;
	long long end = 10e14 * 4;   // 제한 사항 내 최악의 경우
	long long answer = end;

	while (start <= end) {
		long long mid = (start + end) / 2;
		if (isPossible(a, b, g, s, w, t, mid)) {     // mid 안에 옮길 수 있는 경우
			answer = mid < answer ? mid : answer;
			end = mid - 1;
		}
		else start = mid + 1;
	}
	return answer;
}