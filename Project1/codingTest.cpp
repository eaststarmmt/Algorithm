#include<iostream>
#include<string>
using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int test = 1; test <= T; test++) {

		string input;
		cin >> input;
		int cnt = 0;
		for (int i = 0; i < input.size() - 1; i++) {
			if (input[i] != input[i + 1]) cnt++;		// �����̶� �ٸ��� + 1
		}
		if (input[0] == '1') cnt++;			// 1�� ���������� + 1 �� ����� ��
		cout << "#" << test << " " << cnt << "\n";
	}
}
/*
2
0011
100
*/