#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<queue>
#define endl "\n"
using namespace std;

set<string> visited;		// ������ �ܾ ���Դ��� üũ�ϱ� ���� ���. set�� binary search tree �̹Ƿ� �ð����⵵ O(logN)
string sortGame;			
int N, K;

int bfs() {
	string want = sortGame;		
	sort(want.begin(), want.end());		// �Է¹��� �ܾ sort�ؼ� ������ ���� ã�Ƴ���
	queue<pair<string, int>> Q;
	Q.push({ sortGame, 0 });
	visited.insert(sortGame);			// visited�� ���� �ܾ� ����

	while (!Q.empty()) {
		string s = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();

		if (s == want) return cnt;		// �����̸� cnt ���

		for (int i = 0; i <= N - K; i++) {
			string cut = s.substr(i, K);	// i���� K�� �߶󳻱�
			reverse(cut.begin(), cut.end());	// reverse ���̺귯�� �̿�
			string check = s.substr(0, i);		// 0��°���� i�� �� cut���� �߶󳻱� �����κ� �߶�
			check += cut + s.substr(i + K);		// ������ cut�� cut ���� �κ� ���̱�
				
			if (visited.find(check) == visited.end()) {		// visited �� ���Դ��� Ȯ��
				Q.push({ check, cnt + 1 });			// �ܾ �����ٸ� Q�� �ֱ�
				visited.insert(check);				// ���� �ܾ� visited�� ���
			}
		}
	}
	return -1;
}

int main() {
	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		char x;
		cin >> x;
		sortGame += x;
	}

	cout << bfs() << endl;
}