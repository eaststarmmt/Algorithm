#include<iostream>
#include<vector>
#include<string>
#define endl "\n"
using namespace std;

int N, K, maxReadable;
vector<string> word;

void comb(int learn, int cnt, int start) {
	if (cnt == K) {	// K�� ��ŭ �������
		int readable = 0;	// ���� ��� �ܾ�� ���� �� �ִ� �ܾ� ����
		for (int i = 0; i < word.size(); i++) {	// ����� �ܾ� ������ŭ �ݺ�
			int check = 0;						// �ܾ� ��Ʈ�� �ٲ㼭 ������ ����
			for (int j = 0; j < word[i].size(); j++) {	// �ܾ�� ���� �ϳ��ϳ� Ȯ��
				check |= 1 << word[i][j] - 'a';		// �ش� ���ڰ� ���Ե� �� 1�� ǥ��
			}
			if ((learn & check) == check) {		// ��� ���ڿ� �ܾ ���ڸ� and �����ؼ� �� ���� �ܾ�� ������ ���� �� ����
				readable++;
			}
		}
		maxReadable = readable > maxReadable ? readable : maxReadable;	// �ִ밪 ����
		return;
	}
	for (int i = start; i < 26; i++) {
		if (i == 'a' || i == 'c' || i == 'i' || i == 'n' || i == 't')	// �ݵ�� ���ԵǾ�� �ϴ� �ܾ�
			continue;
		int x = 0;	
		x |= 1 << i;		
		if (x & learn) continue;		// i �� learn�� ���� �Ǿ� ������ ���� �ܾ� Ȯ��
		comb(learn | (1 << i), cnt + 1, i + 1);		// ���ο� �ܾ� ��� �� ���. �̷��� �ϸ� ���� �ܾ� ���ö� 1�� �Ȳ��� ��
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		word.push_back(s);
	}	// N ���� �ܾ� ����

	if (K < 5) {
		cout << 0 << endl;
		return 0;
	}

	int learn = 0;
	learn |= 1;	// 'a'
	learn |= 1 << 'c' - 'a';
	learn |= 1 << 'i' - 'a';
	learn |= 1 << 'n' - 'a';
	learn |= 1 << 't' - 'a';

	comb(learn, 5, 0);	// ó�� ���λ� ���̻翡 ���ԵǴ� �ܾ� 5���� ��� ����
	cout << maxReadable << endl;
}