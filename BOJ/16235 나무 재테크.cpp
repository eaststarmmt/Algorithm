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
int A[11][11];		// 겨울마다 줄 양분
int map[11][11];	// 돌리고 있는 맵
deque<Tree> tree;	// 나무들 정보
vector<Tree> die;
vector<Pos> reproduce;

void print() {
	printf("양분 상황\n");
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			printf("%d\t", map[r][c]);
		}
		printf("\n");
	}
}

void printTree() {
	printf("나무 상황\n");
	printf("r\tc\tage\n");
	for (int i = 0; i < tree.size(); i++) {
		printf("%d\t%d\t%d\n", tree[i].r, tree[i].c, tree[i].age);
	}
}

//void printTree2() {
//	printf("나무 상황\n");
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
		if (tree[i].age == INF) tree.pop_back();	// 죽은 나무 있으면 빼기
		else return;	// INF 아니면 그 뒤는 다 살아있음
	}
}

void spring() {
	int size = tree.size();	
	for (int i = 0; i < size; i++) {	// 앞에서부터 처음 있던 사이즈 만큼 돌리기
		int r = tree.front().r;
		int c = tree.front().c;
		int age = tree.front().age;
		tree.pop_front();

		if (map[r][c] >= age) {		// 땅에 양분이 충분히 있을 때
			map[r][c] -= age;		// 양분 빨아먹고 한 살 먹음
			tree.push_back({ r, c, age + 1 });		// 트리 2번에 저장
			if ((age + 1) % 5 == 0) {	// 번식 할 애들 따로 저장
				reproduce.push_back({ r, c });
			}
		}
		else {
			die.push_back({ r, c, age });	// 죽은 나무 따로 저장
		}
	}


	//for (int i = 0; i < tree.size(); i++) {
	//	int r = tree[i].r;
	//	int c = tree[i].c;
	//	int age = tree[i].age;

	//	if (map[r][c] >= age) {		// 땅에 양분이 충분히 있을 때
	//		map[r][c] -= age;		// 양분 빨아먹고 한 살 먹음
	//		tree2.push_back({ r, c, age + 1 });		// 트리 2번에 저장
	//		if ((age + 1) % 5 == 0) {	// 번식 할 애들 따로 저장
	//			reproduce.push_back({ r, c });
	//		}
	//	}
	//	else {
	//		die.push_back({ r, c, age });	// 죽은 나무 따로 저장
	//	}
	//}
}

void summer() {
	for (int i = 0; i < die.size(); i++) {	// 나이 / 2 만큼 양분 추가
		int r = die[i].r;
		int c = die[i].c;
		int age = die[i].age;

		map[r][c] += age / 2;
	}
	die.clear();
}

void fall() {
	int size = reproduce.size();	// 번식할 애들 숫자
	for (int i = 0; i < size; i++) {
		int r = reproduce[i].r;
		int c = reproduce[i].c;
		
		for (int i = 0; i < 8; i++) {	// 8방향 번식
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 1 && nr <= N && nc >= 1 && nc <= N) {		// 땅 범위 내에 있을 때
				tree.push_front({ nr, nc, 1 });
			}
		}
	}
	reproduce.clear();
}

void winter() {		// 겨울에 양분 재충전
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
			map[i][j] = 5;			// 처음에 양분 5로 시작함
		}
	}	// end of nourishment

	for (int i = 0; i < M; i++) {
		int r, c, age;
		scanf("%d %d %d", &r, &c, &age);
		tree.push_back({ r, c, age });	// 나무 정보 받기
	}	// end of input of tree

	sort(tree.begin(), tree.end(), cmp);

	//printf("\n");
	for (int i = 1; i <= K; i++) {	// k년 동안 진행
		//printf("%d년 시작\n", i);
		//printf("\n");
		//printf("양분 먹기 전\n");
		//printTree();
		//print();
		spring();
		//printf("양분 먹은 후\n");
		//print();
		//printTree2();
		summer();
		//printf("죽은애들 양분으로 변한 후\n");
		//print();
		fall();
		//printf("번식 후\n");
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