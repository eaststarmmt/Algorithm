#include <bits/stdc++.h>
using namespace std;

int N, M, T, res, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	
	for(int test = 0; test < T; test++) {
		cin >> N >> M;
		vector<int> a, b;
		res = 0;
		
		for(int i = 0; i < N; i++) {
			cin >> x;
			a.push_back(x);
		}	// end of for
		
		for(int i = 0; i < M; i++) {
			cin >> x;
			b.push_back(x);
		}	// end of for
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		for(int i = 0; i < a.size(); i++) {
			res += lower_bound(b.begin(), b.end(), a[i]) - b.begin();	// a[i] 값 이상이 나오는 최초 인덱스 조회. 그 지점부터 못먹음.
		}
		cout << res << "\n";
		
	}	// end of for test

	return 0;
}