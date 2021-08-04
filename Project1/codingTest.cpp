#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> party[51];
int parent[51];
	
int findParent(int x) {					// 부모가 누군지 찾는 함수
	if (x == parent[x]) return x;
	return findParent(parent[x]);
}

void unionParent(int a, int b) {		// 두개를 합쳐주는 함수
	a = findParent(a);
	b = findParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int know;
	int sum = m;
	vector<int> knowing;			// 진실을 아는 사람들
	scanf("%d", &know);	
	for (int i = 0; i < know; i++) {	// 진실 아는 사람들 저장
		int x;
		scanf("%d", &x);
		knowing.push_back(x);
	}

	for (int i = 0; i < m; i++) {		// 파티 개수만큼 루프
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {	// 파티 오는 사람들 인원 저장
			int x;
			scanf("%d", &x);
			party[i].push_back(x);
		}
	}

	for (int i = 1; i <= n; i++) {	// 부모 자기 자신으로 초기화
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {		// 같은 파티에 있는 사람들 유니온
		for (int j = 1; j < party[i].size(); j++) {
			unionParent(party[i][0], party[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {		// 파티만큼 루프
		for (int j = 0; j < knowing.size(); j++) {	// 파티원 한명과 진실을 아는 사람들 중 한명이라도 부모 같으면 거짓말 불가능
			if (findParent(knowing[j]) == findParent(party[i][0])) {
				sum--;
				break;
			}
		}
		
	}
	printf("%d\n", sum);
}