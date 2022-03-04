#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<sstream>
#include<vector>
#define endl "\n"
typedef long long ll;
using namespace std;

unordered_map<string, int> dictionary;
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if(s.size() >= 3)	// ũ�� 3���� ������ �׳� ������ ��
			sort(s.begin() + 1, s.end() - 1);	// ó�� �ܾ�� �� �ܾ �����ؼ� �ϳ��� �ν��ϰ� ��
		dictionary[s]++;	// �ش� �ܾ� ī����. �߰��� �ٲ�ֵ��� ������ ���� ���� �ֱ� ������
	}	// end of dictionary

	cin >> M;
	cin.ignore();	// �����ִ� \n ������� ��
	
	for (int i = 0; i < M; i++) {
		string input;
		ll res = 1;
		getline(cin, input);	// �� �� ���� �Է�
		stringstream stream(input);	// ���� ���ڿ� stream�� �ֱ�
		vector<string> wordCheck;	// ���� ���� �и��� �ܾ� ���� ����
		while(getline(stream, input, ' ')) {	// ����������� �ڸ� �� ����
			if(input.size() >= 3)		// ũ�� 3���� ������ �׳� ������ ��
				sort(input.begin() + 1, input.end() - 1);
			
			wordCheck.push_back(input);	// üũ�� �ܾ� �־����
		}	// end of one line sentence
		bool flag = false;
		for (int word = 0; word < wordCheck.size(); word++) {
			if (dictionary[wordCheck[word]] > 0) {
				res *= dictionary[wordCheck[word]];
				flag = true;
			}
		}
		if (flag)	// ������ �ܾ �ѹ��̶� ������ ��
			cout << res << endl;
		else		// ������ �ܾ ������ ��
			cout << 0 << endl;
	}	// end of whole sentence
	
}