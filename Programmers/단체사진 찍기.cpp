#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool selected[8];
char friends1[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };  // ���� ���� ���ϸ� �����ϱⰡ �ʹ� �����. �̰� friends�� �ϸ� ��Ÿ�� ������. ������ �𸣰���
int answer;
void permutation(vector<string> data, int cnt, char line[]) {
	if (cnt == 8) {
		for (int i = 0; i < data.size(); i++) {
			char from = data[i][0];     // ���ϴ� ��
			char to = data[i][2];       // Ÿ��
			char oper = data[i][3];     // ������
			int val = 1 + (data[i][4] - '0');      // ���ǿ� �ش��ϴ� ��. �� �پ��ִ°� 1�̱� ������ +1 ����� ��

			int from_idx, to_idx;
			from_idx = to_idx = -1;     // �Ѵ� -1�� �ʱ�ȭ
			for (int j = 0; j < 8; j++) {    // 8�� ��ġ ������ ã�Ƽ� ���� �´��� Ȯ��
				if (line[j] == from) from_idx = j;
				if (line[j] == to) to_idx = j;
				if (from_idx != -1 && to_idx != -1) break;
			}   // end of for 8
			// �ƴ� ��� return �ع����� ī���� �ȵǰ� ����
			if (oper == '=' && val != abs(from_idx - to_idx)) return;
			if (oper == '<' && val <= abs(from_idx - to_idx)) return;
			if (oper == '>' && val >= abs(from_idx - to_idx)) return;
		}   // end of for data
		answer++;    // loop�� ������ ���� �������� ����� ���� �ϳ� �߰�
		return;     // ���� ���� ī���� �����Ƿ� ������ �������� �ʰ� return
	}

	for (int i = 0; i < 8; i++) {    // ���� �����
		if (selected[i]) continue;   // �̹� �����ߴٸ� ����
		selected[i] = true;
		line[cnt] = friends1[i];     // cnt�� �ε����� ����ؼ� ����
		permutation(data, cnt + 1, line);
		selected[i] = false;
	}
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<string> data) {
	answer = 0;
	char line[8] = { 0 };
	permutation(data, 0, line);
	return answer;
}