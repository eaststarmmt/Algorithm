#include<iostream>
#include<string>
#define endl "\n"
using namespace std;

int N;
char input[26][2];

void preOrder(char x) {		// �� ��ġ�� root�� ��
	if (x == '.') return;
	cout << x;						// root�� ó���̹Ƿ� �ڱ� �ڽ� ��� �� ���� �ڽ� ������ �ڽ� ��ͷ� ����
	preOrder(input[x - 'A'][0]);
	preOrder(input[x - 'A'][1]);
}

void inOrder(char x) {
	if (x == '.') return;
	inOrder(input[x - 'A'][0]);	// root�� �߰��� ���� ������ ���� �ڽ����� �� �� �ڽ��� ����ϰ� ������ �ڽ� ��ͷ� ����
	cout << x;
	inOrder(input[x - 'A'][1]);
}

void postOrder(char x) {
	if (x == '.') return;
	postOrder(input[x - 'A'][0]);	// root�� �������� ���� ������ ���� �ڽ� ������ �ڽ��� ��ͷ� �� ���� �ڽ� ���
	postOrder(input[x - 'A'][1]);
	cout << x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		input[root - 'A'][0] = left;	// input[root][���� or ������ �ڽ�] ���·� ����
		input[root - 'A'][1] = right;
	}
	preOrder(65);
	cout << endl;
	inOrder(65);
	cout << endl;
	postOrder(65);
	cout << endl;
}