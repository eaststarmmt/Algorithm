#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void postOrder(string preOrder, string inOrder) {
	int size = preOrder.length();	// 크기
	if (size == 0) return;		// 기저조건
	char root = preOrder[0];	// 루트노드
	int leftTree = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();	// inOrder에서 루트노드 인덱스를 이용하여 왼쪽 서브트리의 노드 개수 찾기
	int rightTree = size - leftTree - 1;	// 오른쪽 서브트리의 노드 개수

	postOrder(preOrder.substr(1, leftTree), inOrder.substr(0, leftTree));	// 왼쪽 서브트리
	postOrder(preOrder.substr(1 + leftTree), inOrder.substr(1 + leftTree));	// 오른쪽 서브트리

	cout << root;	// post order 이므로 루트를 마지막에 출력
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