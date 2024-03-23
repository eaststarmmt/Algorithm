#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int M, int N) {
	int answer = min(M, N) - 1 + (max(M, N) - 1) * min(M, N);
	return answer;
}