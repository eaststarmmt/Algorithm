#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Info {
	int num, c, r;
	Info *left, *right;
};

bool cmp(Info& A, Info& B) {
	if (A.r == B.r) {
		return A.c < B.c;
	}
	return A.r > B.r;
}

vector<Info> infos;

void setTree(Info& root, Info& child) {
	if (root.r <= child.r) return;
	if (root.c > child.c) {
		if (root.left == NULL) {
			root.left = &child;
			return;
		}
		setTree(*root.left, child);		// 왼쪽에 있는데 현재 루트에 왼쪽 자식이 있으면 자식의 자식으로 재귀로 보냄
	}
	else {
		if (root.right == NULL) {
			root.right = &child;
			return;
		}
		setTree(*root.right, child);
	}
}

void setPreOrder(vector<int>& preOrder, Info& root) {
	preOrder.push_back(root.num);
	if (root.left != NULL) {
		setPreOrder(preOrder, *root.left);
	}
	if (root.right != NULL) {
		setPreOrder(preOrder, *root.right);
	}
	return;
}

void setPostOrder(vector<int>& postOrder, Info& root) {
	if (root.left != NULL) {
		setPostOrder(postOrder, *root.left);
	}
	if (root.right != NULL) {
		setPostOrder(postOrder, *root.right);
	}
	postOrder.push_back(root.num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	for (int i = 0; i < nodeinfo.size(); i++) {
		infos.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
	}   // end of for

	sort(infos.begin(), infos.end(), cmp);

	for (int i = 1; i < nodeinfo.size(); i++) {		// 현재 보고 있는 노드를 자식으로 넣는게 목적이라고 생각해야 됨
		setTree(infos[0], infos[i]);
	}   // end of for

	vector<int> preOrder, postOrder;
	setPreOrder(preOrder, infos[0]);
	setPostOrder(postOrder, infos[0]);
	answer.push_back(preOrder);
	answer.push_back(postOrder);
	return answer;
}