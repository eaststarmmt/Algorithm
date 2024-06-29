#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int visited[30];
string message, key, res;
char a[7][7];

void print() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

string get_key(string s) {
	string dis_key;

	for (char c : s) {
		if (visited[c - 'A']) continue;
		visited[c - 'A'] = 1;
		dis_key += c;
	}

	return dis_key;
}

pair<int, int> get_pos(char c) {
	pair<int, int> p;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == c) {
				p = { i, j };
				break;
			}
		}
	}

	return p;
}

string get_res(pair<int, int> apos, pair<int, int> bpos) {
	string s;

	if (apos.first == bpos.first) {
		s += a[apos.first][(apos.second + 1) % 5];
		s += a[apos.first][(bpos.second + 1) % 5];
	}
	else if (apos.second == bpos.second) {
		s += a[(apos.first + 1) % 5][apos.second];
		s += a[(bpos.first + 1) % 5][bpos.second];
	}
	else {
		s += a[apos.first][bpos.second];
		s += a[bpos.first][apos.second];
	}

	return s;
}

string get_message(string s) {
	string message;

	for (int i = 0; i < s.size();) {
		if (s[i] == s[i + 1]) {
			message += s[i];
			if (s[i] == 'X') message += 'Q';
			else message += 'X';
			i++;
		}
		else if (i == s.size() - 1) {
			message += s[i];
			i++;
		}
		else {
			message += s[i];
			message += s[i + 1];
			i += 2;
		}
	}
	return message;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> message >> key;

	string dis_key = get_key(key);

	for (int i = 0, idx = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (idx == dis_key.size()) break;
			a[i][j] = dis_key[idx++];
		}
		if (idx == dis_key.size()) break;
	}

	char c = 'A';
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j]) continue;
			for (; c <= 'Z'; c++) {
				if (visited[c - 'A']) continue;
				if (c == 'J') continue;
				a[i][j] = c;
				visited[c - 'A'] = 1;
				break;
			}
		}
	}

	string dis_message = get_message(message);

	if (dis_message.size() % 2) dis_message += 'X';

	for (int i = 0; i < dis_message.size(); i += 2) {
		char a = dis_message[i];
		char b = dis_message[i + 1];

		pair<int, int> apos = get_pos(a);
		pair<int, int> bpos = get_pos(b);

		res += get_res(apos, bpos);
	}

	cout << res << '\n';
	return 0;
}