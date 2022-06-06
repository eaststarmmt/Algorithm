#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
string remain = "0123456789";
bool checkPrime(long long num) {    // 소수 체크
	if (num < 2) return false;
	else if (num <= 3) return true;
	for (long long i = 2; i <= sqrt(num); i++) { // 제곱근까지만 확인하면 됨
		if (num % i == 0) return false;
	}
	return true;
}

string setNumber(int n, int k) {
	string number;
	while (n > 0) {
		number += remain[n % k];
		n /= k;
	}   // end of for
	reverse(number.begin(), number.end());
	return number;
}

int solution(int n, int k) {
	int answer = 0;
	string number = setNumber(n, k);
	long long num = 0;
	for (int i = 0; i < number.size(); i++) {
		if (number[i] != '0') {
			num = num * 10 + (number[i] - '0');
		}
		else {
			if (num != 0) {
				if (checkPrime(num)) {
					answer++;
				}
			}
			num = 0;
		}
	}
	if (checkPrime(num))     // 0을 만날때 판단하기 때문에 마지막 숫자는 포함되지 않음
		answer++;
	return answer;
}