#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
	int answer = 0;
	if (eq == "=" && n == m) answer = 1;
	else if (ineq == ">") answer = n > m ? 1 : 0;
	else answer = n < m ? 1 : 0;
	return answer;
}