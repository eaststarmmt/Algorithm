#include <bits/stdc++.h>
using namespace std;

int N, M, res, a[100004], lo = 1, hi;

bool check(int mid) {
	for(int i = 0; i < N; i++) {
		if(a[i] > mid) return false;	// 하나라도 블루레이 크기보다 크면 불가능
	}	// end of for
	
	int cnt = 0;	// 블루레이 개수를 셀 변수
	int temp = mid;	// mid 값으로 남은 공간을 확인해야 하기 때문에 temp에 저장해 놓음
	
	for(int i = 0; i < N; i++) {
		if(mid < a[i]) {	// 현재 블루레이에 저장이 안되어 다음 블루레이에 저장해야 되는 경우
			cnt++;
			mid = temp;		// temp에서 원래 있던 mid 값 가져옴
		}
		
		mid -= a[i];	// 남은 공간 빼줌
	}	// end of for
	
	if(mid != temp) cnt++;	// 마지막 블루레이에 담겨있으면 카운팅
	
	return cnt <= M;	// M을 넘어가면 안됨.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		hi += a[i];	// 이분 탐색의 최대값 구하기 위해.
	}	// end of for
	
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		
		if(check(mid)) {	// 개수가 M 이하인 원하는 경우. 계속 반복하면 mid가 최솟값이 된다.
			res = mid;
			hi = mid - 1;
		} else {			// 개수가 M 초과인 경우
			lo = mid + 1;
		}
	}
	
	cout << res << "\n";
	
	return 0;
}