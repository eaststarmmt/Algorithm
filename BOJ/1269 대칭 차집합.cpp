#include <bits/stdc++.h>
using namespace std;

int A, B, res;
map<int, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A >> B;
	
	// A 집합과 B 집합에 숫자를 map에다 카운팅. 한번만 나온 숫자가 차집합의 원소임
	for(int i = 0; i < A; i++) {
		int x;
		cin >> x;
		m[x]++;
	}	// end of for A
	
	for(int i = 0; i < B; i++) {
		int x;
		cin >> x;
		m[x]++;
	}	// end of for B
	
	// 한번 나온 숫자의 개수 카운팅
	for(pair<int, int> i : m) {
		if(i.second == 1) res++;
	}	// end of for
	
	cout << res << "\n";
	
	return 0;
}