#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, L;
vector<int> rest;

int divideCon(int start, int end) {
	
	int min = (int)1e9;

	while (start <= end) {
		int cnt = 0;
		int mid = (start + end) / 2;	// mid 간격마다 휴게소 하나씩 세울 예정. 즉 mid가 간격의 최대값임

		for (int i = 1; i < rest.size(); i++) {
			int dist = rest[i] - rest[i - 1];	// 휴게소 간격
			cnt += dist / mid;		// ex mid가 70이고 간격이 144이면 2개 지을수 있음
			if (dist % mid == 0) cnt--;	// ex mid 70 간격 140일때 2개 지으면 마지막에 겹침. 그래서 -1
		}

		if (cnt > M) start = mid + 1;
		else {
			end = mid - 1;
			min = mid < min ? mid : min;	// cnt가 작은 경우에는 M과 같을때보다 값이 크게 나옴. 그래서 이때 최소값을 따져야됨
		}
			
	}
	return min;
}

int main() {
	scanf("%d %d %d", &N, &M, &L);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		rest.push_back(x);
	}
	rest.push_back(0);	// 가장 앞에 휴게소 간격 구하는 용도
	rest.push_back(L);	// 마지막 휴게소와 고속도로의 끝의 간격 구하는 용도
	sort(rest.begin(), rest.end());	// 이분탐색을 위한 정렬

	printf("%d\n", divideCon(1, L - 1));	// 도로의 끝은 안되므로 L - 1
}