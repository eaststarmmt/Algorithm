// ���� �������� 
#include<iostream>
#include<string>
using namespace std;

int n;													// ����� ���� ī���� �ϱ� ���� ���������� ����
void recursive(int x) {
	string under = "";
	for(int i = 0; i < n - x; i++) under += "____";		// n - x ��ŭ ����� ���
	cout << under << "\"����Լ��� ������?\"\n";
	if (x == 0) {										// ������ ���
		cout << under << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	
	}
	else {												// �� ���� ���
		cout << under << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		cout << under << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";		
		cout << under << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		recursive(x - 1);
	}
	cout << under << "��� �亯�Ͽ���.\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

	recursive(n);
}