// �����ǵ��� ���̺귯���� �ƴ� ���� �����ض� ������.... 
// ���� �̴°� ���� ������ ��͸� �ʹ� ���� ���� �޸� �ʰ��� ���°� �غ� ����
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string input;
	int n;
	while (!(cin >> input >> n).eof()) {		// �Է��� �޾����� ����
		bool output = false;					// ���� ����� ���� n���� �Ѿ�� output�� ������ false�� ��������
		string result = input;
		int i = 0;
		do {									// do while�� ����ϴ� ������ ������ ó������ next_permutation�� ���� �Ǳ� ����
			i++;
			if (i == n) {				
				cout << input << " " << n << " = " << result << "\n";
				output = true;
			}
		} while (next_permutation(result.begin(), result.end()));
		if (!output)
			cout << input << " " << n << " = No permutation\n";
	}
}