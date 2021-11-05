#include<iostream>
#include<string>
#define endl "\n"
using namespace std;

int N;
char input[26][2];

void preOrder(char x) {		// 현 위치를 root로 봄
	if (x == '.') return;
	cout << x;						// root가 처음이므로 자기 자신 출력 후 왼쪽 자식 오른쪽 자식 재귀로 들어가기
	preOrder(input[x - 'A'][0]);
	preOrder(input[x - 'A'][1]);
}

void inOrder(char x) {
	if (x == '.') return;
	inOrder(input[x - 'A'][0]);	// root를 중간에 보기 때문에 왼쪽 자식으로 들어가 후 자신을 출력하고 오른쪽 자식 재귀로 들어가기
	cout << x;
	inOrder(input[x - 'A'][1]);
}

void postOrder(char x) {
	if (x == '.') return;
	postOrder(input[x - 'A'][0]);	// root를 마지막에 보기 때문에 왼쪽 자식 오른쪽 자식을 재귀로 다 보고 자신 출력
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
		input[root - 'A'][0] = left;	// input[root][왼쪽 or 오른쪽 자식] 형태로 저장
		input[root - 'A'][1] = right;
	}
	preOrder(65);
	cout << endl;
	inOrder(65);
	cout << endl;
	postOrder(65);
	cout << endl;
}