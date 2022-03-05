#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<pair<int, int>> line;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		line.push_back({ a, b });
	}
	sort(line.begin(), line.end(), cmp);
	int ans = 0;
	int start = line[0].first;
	int end = line[0].second;

	for (int i = 1; i < N; i++) {
		int nowStart = line[i].first;
		int nowEnd = line[i].second;
		if (end > nowStart) {	// 이전 선분의 끝이 지금 선분의 시작보다 뒤에 있으면 겹침
			end = nowEnd > end ? nowEnd : end;	// 선이 연장됐다는 개념으로 끝부분 늘려줌
		}
		else {	// 겹치지 않은 경우
			ans += end - start;		// 지금까지 잡고 있던 선분 길이 저장
			start = nowStart;		// 비교할 선분을 현재 선분으로 바꿔줌
			end = nowEnd;
		}
	}

	ans += end - start;
	cout << ans << endl;
}