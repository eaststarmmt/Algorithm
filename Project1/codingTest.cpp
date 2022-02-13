#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int start = 0;
	int end = people.size() - 1;
	int escape = 0;     // 탈출한 사람 수
	while (start < end) {    // 투포인터 개념
		if (people[start] + people[end] <= limit) {  // 두명이 다 나가지는 경우
			answer++;
			escape += 2;
			start++;
			end--;
		}
		else {    // 덜 무거운 사람으로 바꿔서 다음 루프에서 나가지는지 확인하기
			end--;
		}
	}
	answer += people.size() - escape;   // 두명씩 탈출 못한 사람들 숫자 만큼 
	return answer;
}