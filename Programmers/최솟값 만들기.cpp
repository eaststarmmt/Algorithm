#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.begin(), A.end());   // 하나는 오름차순 하나는 내림차순으로 정렬하여 곱의 크기를 최소화
	sort(B.begin(), B.end(), cmp);

	for (int i = 0; i < A.size(); i++) {
		answer += A[i] * B[i];
	}   // end of for

	return answer;
}