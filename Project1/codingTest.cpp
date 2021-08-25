#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		string input[5];		// �Է��� 5����� �������� ������ string 5�� ����
		int maxLenghth = -1;	// ���� �� ������ üũ
		for (int i = 0; i < 5; i++) {
			cin >> input[i];
			int x = input[i].size();	// size() �Լ��� int Ÿ���� �ƴϹǷ� ���� int�� �����س��� ����ؾߵ�
			maxLenghth = max(x, maxLenghth);
		}
		cout << "#" << test << " ";
		for (int i = 0; i < maxLenghth; i++) {		// ������ �ִ� ���� ����
			for (int j = 0; j < 5; j++) {		
				int x = input[j].size();			
				if (x > i) cout << input[j][i];		// string ���̰� �ʰ����� �ʾ����� ���
			}
		}
		cout << "\n";
	}
}