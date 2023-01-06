#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int l, r, from, to, res, N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		cin >> from >> to;
		v.push_back({from, to});
	}	// end of for
	
	sort(v.begin(), v.end());	// 시작점 기준으로 정렬
	
	l = v[0].first;		// 처음 값을 넣어야 비교가 쉬움
	r = v[0].second;
	
	for(int i = 1; i < v.size(); i++) {
		if(v[i].first > r) {		// 선이 이어지지 않는 경우.
			res += r - l;			// 지금까지 측정한 길이 더해주고 양 끝점 새로 저장
			l = v[i].first;
			r = v[i].second;
		} else if(v[i].second > r) {	// 선이 이어지는 경우. 시작점 오름차순이라 시작점 신경 쓸 필요 없음
			r = v[i].second;
		}
	}	// end of for
	
	res += r - l;	// 반복문이 종료될때 마지막 양 끝점은 계산이 안되어 있음. 그래서 추가
	cout << res << "\n";
	
	return 0;
}