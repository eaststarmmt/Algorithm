#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool selected[8];
unordered_set<string> ban;
bool check(string user, string banned) {
	if (user.size() != banned.size()) return false;
	for (int i = 0; i < user.size(); i++) {
		if (banned[i] == '*') continue;
		if (banned[i] != user[i]) return false;
	}

	return true;
}

void comb(int bIdx, vector<string>& user_id, vector<string>& banned_id) {
	if (bIdx == banned_id.size()) {
		string list;
		for (int i = 0; i < user_id.size(); i++) {
			if (selected[i]) continue;
			list += user_id[i];
		}
		ban.insert(list);
		return;
	}

	for (int i = 0; i < user_id.size(); i++) {	// 유저는 처음부터 끝까지 다 봐야됨. 확인하는 기준은 banned user
		if (selected[i] || !check(user_id[i], banned_id[bIdx])) {	// 이미 등록된 유저 이거나 글자 안맞으면 무시
			continue;
		}
		selected[i] = true;
		comb(bIdx + 1, user_id, banned_id);
		selected[i] = false;
	}

}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	comb(0, user_id, banned_id);
	answer = ban.size();
	return answer;
}