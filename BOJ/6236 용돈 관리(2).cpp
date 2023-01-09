#include <bits/stdc++.h>
using namespace std;

long long hi, lo = 1, res;
int a[100004], N, M, mx;

bool check(long long mid) {
	if(mx > mid) return false;
	
	int cnt = 1;
	long long temp = mid;
	
	for(int i = 0; i < N; i++) {
		if(mid < a[i]) {	// 충전이 필요한 경우
			mid = temp;
			cnt++;
		}
		
		mid -= a[i];
	}	// end of for
	
	return cnt <= M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		hi += a[i];
		mx = max(a[i], mx);
	}	// end of for
	
	// 이분탐색
	while(lo <= hi) {
		long long mid = (lo + hi) / 2;
		
		if(check(mid)) {
			hi = mid - 1;
			res = mid;
		} else {
			lo = mid + 1;
		}
	}	// end of while
	
	cout << res << "\n";
	return 0;
}