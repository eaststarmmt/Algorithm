#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	// 승점만 확인하면 되므로 오름차순 정렬
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0, j = 0; i < A.size() && j < B.size(); i++, j++) {
		for (; j < B.size(); j++) {
			if (A[i] < B[j]) {   // B가 A를 가장 작은 숫자로 이기는 형태로 카운팅
				answer++;
				break;
			}
		}   // end of for j
	}   // end of for i

	return answer;
}