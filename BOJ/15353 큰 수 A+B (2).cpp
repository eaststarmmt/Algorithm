#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string A, string B) {
	string res;
	int sum = 0;

	while (!A.empty() || !B.empty() || sum) {	// sum이 0이 아니면 얘도 넣어 줘야됨. 이거 놓치면 대참사남
		if (!A.empty()) {
			sum += A.back() - '0';
			A.pop_back();
		}
		if (!B.empty()) {
			sum += B.back() - '0';
			B.pop_back();
		}
		res += (sum % 10) + '0';	// 다음 자리에서 10의 자리는 계산해야 하므로 1의 자리만 넣기
		sum /= 10;
	}	// end of while

	reverse(res.begin(), res.end());
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A, B;
	cin >> A >> B;

	cout << add(A, B) << "\n";
	return 0;
}