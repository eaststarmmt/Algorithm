#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[304][304], cnt[304]; // 인덱스, 길이
int N, M, K, T, a, b;
vector<pair<int, int>> v;   // 인원, 길이. 구간을 나눈 벡터

int go(int here, int num, int prev) {   // 남은 인원, 인덱스, 직전에 사용된 인원
	if (here == v.size()) return 0;  // 벡터의 인덱스 끝까지 간 경우 종료
	// 메모이제이션
	int &ret = dp[here][num];
	if (ret) return ret;

	int cost = max(0, T - v[here].first);   // T를 맞추기 위한 최소 인원.
	int real_cost = prev - cost >= 0 ? 0 : cost - prev; // 이전에 투입 된 인원이 더 많으면 투입할 필요 없고, 적으면 필요한 만큼 투입

	if (num - real_cost >= 0) {  // 필요한 인원이 충분히 있는 경우
		// 현재 구간에 인원을 투입하는 경우와 투입하지 않는 경우 중 더 큰 경우 저장 후 리턴
		return ret = max(go(here + 1, num - real_cost, cost) + v[here].second, go(here + 1, num, 0));
	}
	else return ret = go(here + 1, num, 0);   // 투입이 불가능하므로 이번 구간 건너뛰고 다음 구간으로 넘어가기

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> T;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		for (int j = a; j < b; j++) {
			cnt[j] = min(T, ++cnt[j]);  // T를 넘어가면 의미 없기 때문
		}   // end of for cnt
	}   // end of for M

	int time = 1;   // 구간의 길이
	int num = cnt[1];   // 인원

	for (int i = 2; i <= N; i++) {
		if (num != cnt[i]) {     // 인원이 달라졌으므로 다른 구간임을 의미. 이전구간 벡터에 저장
			v.push_back({ num, time });
			num = cnt[i];
			time = 0;
		}
		time++;
	}   // end of for i

	v.push_back({ num, time });

	cout << go(0, K, 0) << '\n';
	return 0;
}