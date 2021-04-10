#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> vec, sortVec;	//값 찾을때 쓸 벡터와 정렬할 벡터 따로 관리
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
		sortVec.push_back(x);
	}
	sort(sortVec.begin(), sortVec.end());
	sortVec.erase(unique(sortVec.begin(), sortVec.end()), sortVec.end());	//중복된 값 제거
	
	int cnt;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		cnt += lower_bound(sortVec.begin(), sortVec.end(), vec[i]) - sortVec.begin();	//찾고자 하는 벡터의 값의 인덱스 찾기. 오름차순 이므로 인덱스 값 = 작은 원소의 개수가 됨
		printf("%d ", cnt);
	}
	printf("\n");
}