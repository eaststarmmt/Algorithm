#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> id_list;		// �����ų� ���� ��� id�� ������ ����
unordered_map<string, string> nicks;	// ���̵�� �г��� ���ν�Ű�� ���� ������ ��
vector<string> answer;

void stringTokenizer(string s) {
	stringstream stream(s);
	int idx = 0;
	string id, nick;
	bool flag = false;
	while (getline(stream, s, ' ')) {    // ���� �������� ���ڿ� ����. Leave�� ��� idx�� 2�϶� while���� ���� ����
		if (idx == 0) {
			if (s == "Enter") {
				answer.push_back("���� ���Խ��ϴ�.");    // �ϴ� �̰ɷ� ����
				flag = true;  // ���̵� �����ؾ� �Ǵ� �÷���    
			}
			else if (s == "Leave") {
				answer.push_back("���� �������ϴ�.");    // �ϴ� �̰ɷ� ����
				flag = true;  // ���̵� �����ؾ� �Ǵ� �÷���
			}
		}
		else if (idx == 1) {
			id = s;         // �ι�° �ܾ� ���̵� �ֱ�

			if (flag) {       // �����ų� ���� ��� ���̵� ����
				id_list.push_back(id);
			}

		}
		else if (idx == 2) {
			nick = s;       // ����° �ܾ� �г��ӿ� �ֱ�
			nicks[id] = nick;   // ���̵� �������� �г��� �ʿ� �����ؼ� ������ ������ ��� ���ŵ�
		}
		idx++;
	}   // end of while stream

	return;
}

vector<string> solution(vector<string> record) {

	for (int i = 0; i < record.size(); i++) {
		stringTokenizer(record[i]);
	}   // end of for

	for (int i = 0; i < answer.size(); i++) {    // answer�� id �߰�
		answer[i] = nicks[id_list[i]] + answer[i];
	}
	return answer;
}