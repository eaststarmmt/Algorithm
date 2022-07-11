#include <iostream>
#include <unordered_map>
#include <string>
#include <regex>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	unordered_map<int, string> dic_num;
	unordered_map<string, int> dic_name;

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		dic_num[i] = s;
		dic_name[s] = i;
	}

	regex re("\\d");

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (regex_match(s, re)) {
			cout << dic_num[stoi(s)] << "\n";
		}
		else {
			cout << dic_name[s] << "\n";
		}
	}

	return 0;
}