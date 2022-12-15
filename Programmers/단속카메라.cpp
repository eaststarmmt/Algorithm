#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	sort(routes.begin(), routes.end(), cmp);    // 나가는 지점 기준으로 오름차순 정렬

	int idx = 0;
	int size = routes.size();

	while (idx < size) {
		int cam = routes[idx][1];   // 카메라 위치는 아직까지 안나간 첫번째 차의 나가는 위치

		for (idx++; idx < size; idx++) { // cam 위치에 걸쳐지는 차량들 제외
			if (cam < routes[idx][0] || cam > routes[idx][1]) break;
		}   // end of for

		answer++;
	}   // end of while

	return answer;
}