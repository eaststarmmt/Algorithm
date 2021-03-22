#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int binarySearch(vector<int> vec, int target, int start, int end) {
	int maxDis = 0;
	int cnt, dis, pos;
	while (start <= end) {
		int mid = (start + end) / 2;
		cnt = 1;	//처음 위치에 한개는 설치 한다 가정하고 1로 시작
		pos = 0;	//마지막에 설치한 공유기 인덱스 표시할 변수
		for (int i = 1; i < vec.size(); i++) {
			dis = vec[i] - vec[pos];
			if (dis >= mid) {
				cnt++;
				pos = i;	//공유기 인덱스 표시
			}
		}
		if (cnt >= target) {
			start = mid + 1;
			maxDis = max(mid, maxDis);	//mid 값을 기준으로 하므로 최소 거리가 mid 값임
		}

		else end = mid - 1;
			
	}
	return maxDis;
}

int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	printf("%d \n", binarySearch(vec, c, 0, vec[vec.size() - 1]));	//이분탐색을 위해 target을 공유기 갯수로 잡아야됨 
}