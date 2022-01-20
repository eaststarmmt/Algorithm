#include<cstdio>
#include<vector>
#include<algorithm>
#include<deque>
#define INF 1e9
using namespace std;

struct Tree {
	int r, c, age;
};

struct Pos {
	int r, c;
};

int dr[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dc[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int N, M, K;
int A[11][11];		// �ܿ︶�� �� ���
int map[11][11];	// ������ �ִ� ��
deque<Tree> tree;	// ������ ����
vector<Tree> die;
vector<Pos> reproduce;

void print() {
	printf("��� ��Ȳ\n");
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			printf("%d\t", map[r][c]);
		}
		printf("\n");
	}
}

void printTree() {
	printf("���� ��Ȳ\n");
	printf("r\tc\tage\n");
	for (int i = 0; i < tree.size(); i++) {
		printf("%d\t%d\t%d\n", tree[i].r, tree[i].c, tree[i].age);
	}
}

//void printTree2() {
//	printf("���� ��Ȳ\n");
//	printf("r\tc\tage\n");
//	for (int i = 0; i < tree2.size(); i++) {
//		printf("%d\t%d\t%d\n", tree2[i].r, tree2[i].c, tree2[i].age);
//	}
//}

bool cmp(Tree a, Tree b) {
	return a.age < b.age;
}

void dieTree() {
	sort(tree.begin(), tree.end(), cmp);
	int size = tree.size();
	for (int i = size - 1; i >= 0; i--) {
		if (tree[i].age == INF) tree.pop_back();	// ���� ���� ������ ����
		else return;	// INF �ƴϸ� �� �ڴ� �� �������
	}
}

void spring() {
	int size = tree.size();	
	for (int i = 0; i < size; i++) {	// �տ������� ó�� �ִ� ������ ��ŭ ������
		int r = tree.front().r;
		int c = tree.front().c;
		int age = tree.front().age;
		tree.pop_front();

		if (map[r][c] >= age) {		// ���� ����� ����� ���� ��
			map[r][c] -= age;		// ��� ���Ƹ԰� �� �� ����
			tree.push_back({ r, c, age + 1 });		// Ʈ�� 2���� ����
			if ((age + 1) % 5 == 0) {	// ���� �� �ֵ� ���� ����
				reproduce.push_back({ r, c });
			}
		}
		else {
			die.push_back({ r, c, age });	// ���� ���� ���� ����
		}
	}


	//for (int i = 0; i < tree.size(); i++) {
	//	int r = tree[i].r;
	//	int c = tree[i].c;
	//	int age = tree[i].age;

	//	if (map[r][c] >= age) {		// ���� ����� ����� ���� ��
	//		map[r][c] -= age;		// ��� ���Ƹ԰� �� �� ����
	//		tree2.push_back({ r, c, age + 1 });		// Ʈ�� 2���� ����
	//		if ((age + 1) % 5 == 0) {	// ���� �� �ֵ� ���� ����
	//			reproduce.push_back({ r, c });
	//		}
	//	}
	//	else {
	//		die.push_back({ r, c, age });	// ���� ���� ���� ����
	//	}
	//}
}

void summer() {
	for (int i = 0; i < die.size(); i++) {	// ���� / 2 ��ŭ ��� �߰�
		int r = die[i].r;
		int c = die[i].c;
		int age = die[i].age;

		map[r][c] += age / 2;
	}
	die.clear();
}

void fall() {
	int size = reproduce.size();	// ������ �ֵ� ����
	for (int i = 0; i < size; i++) {
		int r = reproduce[i].r;
		int c = reproduce[i].c;
		
		for (int i = 0; i < 8; i++) {	// 8���� ����
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 1 && nr <= N && nc >= 1 && nc <= N) {		// �� ���� ���� ���� ��
				tree.push_front({ nr, nc, 1 });
			}
		}
	}
	reproduce.clear();
}

void winter() {		// �ܿ￡ ��� ������
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] += A[i][j];
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			map[i][j] = 5;			// ó���� ��� 5�� ������
		}
	}	// end of nourishment

	for (int i = 0; i < M; i++) {
		int r, c, age;
		scanf("%d %d %d", &r, &c, &age);
		tree.push_back({ r, c, age });	// ���� ���� �ޱ�
	}	// end of input of tree

	sort(tree.begin(), tree.end(), cmp);

	//printf("\n");
	for (int i = 1; i <= K; i++) {	// k�� ���� ����
		//printf("%d�� ����\n", i);
		//printf("\n");
		//printf("��� �Ա� ��\n");
		//printTree();
		//print();
		spring();
		//printf("��� ���� ��\n");
		//print();
		//printTree2();
		summer();
		//printf("�����ֵ� ������� ���� ��\n");
		//print();
		fall();
		//printf("���� ��\n");
		//printTree2();
		winter();
		//printf("\n");


	}

	printf("%d\n", tree.size());
}

/*
5 2 7
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3
Answer: 71
*/