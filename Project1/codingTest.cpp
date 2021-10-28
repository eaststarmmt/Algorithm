#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define endl "\n"
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<string>> input(201);	// counting sort�� ���� vector. 200�� ���� �ǹǷ� 201�� ����
	for (int i = 0; i < N; i++) {
		int x;
		string s;
		cin >> x >> s;			
		input[x].push_back(s);	// ���̰� x�� ������� ��ϵ� ������� ��ġ��
	}
	int cnt = 0;
	for (int i = 1; i < 201; i++) {	// 1����� 200�� ���� Ȯ��
		if (input[i].size() == 0) continue;	// �ش� ������ ����� ������ �ǳʶٱ�
		for (string s : input[i]) {
			cout << i << " " << s << endl;	
			cnt++;
		}
		if (cnt == N) return 0;	// N�� �������� �ڿ� ��� �����Ƿ� ����
	}
}