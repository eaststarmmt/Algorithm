#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void postOrder(string preOrder, string inOrder) {
	int size = preOrder.length();	// ũ��
	if (size == 0) return;		// ��������
	char root = preOrder[0];	// ��Ʈ���
	int leftTree = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();	// inOrder���� ��Ʈ��� �ε����� �̿��Ͽ� ���� ����Ʈ���� ��� ���� ã��
	int rightTree = size - leftTree - 1;	// ������ ����Ʈ���� ��� ����

	postOrder(preOrder.substr(1, leftTree), inOrder.substr(0, leftTree));	// ���� ����Ʈ��
	postOrder(preOrder.substr(1 + leftTree), inOrder.substr(1 + leftTree));	// ������ ����Ʈ��

	cout << root;	// post order �̹Ƿ� ��Ʈ�� �������� ���
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string preOrder, inOrder;

	while (cin >> preOrder >> inOrder) {
		postOrder(preOrder, inOrder);
		cout << "\n";
	}
}