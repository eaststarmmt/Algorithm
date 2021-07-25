#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	stack<char> stick;
	stick.push(input[0]);		// ó���� ������ ���� ��
	int sum = 0;
	for (int i = 1; i < input.size(); i++) {
		if (input[i] == '(') stick.push('(');	// ( ������ ������ push
		else {									// ) ������ ������ pop
			stick.pop();
			if (input[i - 1] == '(') {			// �ٷ� ���� ( ������ ��ƽ ���� ��ŭ ������
				sum += stick.size();
			}
			else {				// �߸� �κ��� ���������� ���� �ִ� ������ �������� ���߱� ������
				sum++;			// �������� �ƴ϶�� ������̹Ƿ� 1�� �����ش�
			}
		}
	}
	cout << sum << "\n";
}