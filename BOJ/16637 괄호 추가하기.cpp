#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
string s;
vector<int> num;
vector<char> oper;
int res = -1e9;
int calc(char o, int a, int b) {
	if (o == '+') return a + b;
	if (o == '*') return a * b;
	if (o == '-') return a - b;
}

void comb(int here, int nSum) {
	if (here == num.size() - 1) {
		res = max(res, nSum);
		return;
	}

	comb(here + 1, calc(oper[here], nSum, num[here + 1]));	// ������� ����ϴ� ���

	if (here + 2 <= num.size() - 1) {
		int sum = calc(oper[here + 1], num[here + 1], num[here + 2]);	// �ڿ� ���� ���
		comb(here + 2, calc(oper[here], nSum, sum));	// ���� ����� ����� ���ݱ����� ��� ��� ���
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 1) oper.push_back(s[i]);
		else num.push_back(s[i] - '0');
	}	// end of for

	comb(0, num[0]);
	cout << res << "\n";
	return 0;
}