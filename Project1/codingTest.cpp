#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string name) {
	int answer = 0;
	int len = name.size();
	int mid = len / 2;
	int front = 0;      // 앞으로 부터 거리
	int front_to_mid = 0;   // 앞에서 중간까지 거리
	int end = 0;        // 뒤로부터 거리
	int end_to_mid = 0; // 중간부터 뒤까지 거리
	// 중간을 기준으로 앞쪽과 뒤쪽 마지막으로 A가 아닌 부분 확인해야 됨
	for (int i = 0; i < len; i++) {
		answer += name[i] - 'A' <= 13 ? name[i] - 'A' : 'Z' - name[i] + 1;    // 알파벳 바꾸는 횟수
		if (name[i] != 'A') {    // 앞에서부터의 거리 계산
			front = i;
			if (i <= mid)
				front_to_mid = i;   // 중간 전이면 거리 저장
		}
		if (name[len - i] != 'A') {    // front와 같음
			end = i;
			if (len - i > mid)
				end_to_mid = i;
		}
	}
	answer += min(min(front, end), min(2 * front_to_mid + end_to_mid, 2 * end_to_mid + front_to_mid));
	return answer;
}