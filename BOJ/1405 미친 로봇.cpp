#include<iostream>
#define endl "\n"
using namespace std;

int N;
double prob[4];		// 0: �� 1: �� 2: �� 3: ��
bool visited[29][29];

int dr[] = { 0, 0, 1, -1 };		// ������������ ������
int dc[] = { 1, -1, 0, 0 };
double result = 0;

void dfs(int r, int c, int cnt, double probability) {
	if (cnt == N) {			// Depth ������ ���µ� ó�� �� ���̸� Ȯ�� ���ϱ�
		result += probability;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (visited[r + dr[i]][c + dc[i]]) continue;	// �̹� �湮 ������ ����

		visited[nr][nc] = true;			//	�湮 ó��
		if (cnt == 0)
			dfs(nr, nc, cnt + 1, prob[i]);	// ó�� ���� ������ ���ϸ� 0�� �������Ƿ� �� ���⿡ ���� Ȯ�� �״�� �ֱ�
		else 
			dfs(nr, nc, cnt + 1, probability * prob[i]);	// ex) ���� ���ٰ� ���� �� Ȯ�� = ���� * ����
		visited[nr][nc] = false;		//	������ �ٸ� ��� �̹Ƿ� �湮 ó�� ����
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 4; i++) {
		double x;
		cin >> x;
		prob[i] = x / 100;
	}

	visited[14][14] = true;
	dfs(14, 14, 0, 0);
	cout.precision(10);			// �Ҽ��� 10°¥������ ǥ��. 10^-9�� ���� ���� �̹Ƿ� �ϳ� �� ǥ���ؾ� ��Ʋ��
	cout << result << endl;
}