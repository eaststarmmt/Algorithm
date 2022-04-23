#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 1;     // 처음에 바로 만나는 경우가 1이므로 1로 시작
	a--;    // 인덱스를 1 ~ N 이 아닌 0 ~ N - 1로 변경
	b--;    // 0 ~ N - 1 인 경우 /2를 하면 대진하는 상대끼리는 같은 값이 나옴
	while (a / 2 != b / 2) {
		a /= 2;
		b /= 2;
		answer++;
	}

	return answer;
}