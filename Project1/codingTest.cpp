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
		string repeat;
		int cnt = 0;
		int start;
		for (int i = 1; i < input.size(); i++) {
			if (input[i] == input[0]) {			// ù ���ڿ� ������ �켱 �ݺ� �ǽ�
				repeat = input.substr(0, i);	// 0������ ������ġ �������� �߶�
				if (i * 2 <= 30 && repeat == input.substr(i, i)) {	// ���������� �ݺ��Ǵ��� Ȯ��
					cnt = i;	// i���� �߶� ������ �����̹Ƿ� ���
					break;
				}
			}
		}
		cout << "#" << test << " "<< cnt<< "\n";
	}
}