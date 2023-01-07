#include <bits/stdc++.h>
#define INF 1e18
using namespace std;

long long a[300004], lo = 1, hi, N, M, res = INF;

bool check(long long mid) {	// mid는 1인당 받는 최대 개수
	long long num = 0;	// 몇명한테 줄 수 있는지
	
	for(int i = 0; i < M; i++) {
		num += a[i] / mid;
		if(a[i] % mid) num++;	// 나머지가 있으면 한명 더 받을 수 있음
	}	// end of for
	
	return num <= N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		cin >> a[i];
		hi = max(hi, a[i]);		// 가장 큰 값 기준으로 잡기 위해 저장
	}
	// 이분탐색
	while(lo <= hi) {
		long long mid = (lo + hi) / 2;
		
		if(check(mid)) {
			res = min(res, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}	// end of while
	
	cout << res << "\n";
	
	return 0;
}