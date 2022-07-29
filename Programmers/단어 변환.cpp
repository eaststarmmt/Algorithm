#include <string>
#include <vector>
#include <queue>

using namespace std;
struct Info {   // 현재 단어, 변환된 수
	string s;
	int cnt;
};

bool visited[50];

bool check(string s, string word) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == word[i]) cnt++;
	}
	if (cnt == s.size() - 1) return true;    // 다른 글자 한 개면 true 아니면 false
	return false;
}

int bfs(string begin, string target, vector<string>& words) {
	queue<Info> Q;
	Q.push({ begin, 0 });

	while (!Q.empty()) {
		string s = Q.front().s;
		int cnt = Q.front().cnt;
		Q.pop();

		if (target == s) {
			return cnt;
		}

		for (int i = 0; i < words.size(); i++) {
			if (visited[i] || !check(s, words[i])) { // 방문한 적 있는 단어이거나 두 글자 이상 다르면 무시
				continue;
			}
			Q.push({ words[i], cnt + 1 });
			visited[i] = true;

		}   // end of for words

	}   // end of while

	return 0;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	answer = bfs(begin, target, words);
	return answer;
}