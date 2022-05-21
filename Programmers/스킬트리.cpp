#include <string>
#include <vector>
using namespace std;

bool check(string target, string& skill) {
	for (int i = skill.size() - 1, t_idx = 1e9; i >= 0; i--) {   // 뒤쪽 스킬부터 조회
		int idx = target.find(skill[i]);
		if (idx == string::npos && t_idx == 1e9) continue;   // 아무것도 안배웠고 현재 스킬도 안배운 경우
		if (t_idx != 1e9) {
			if (idx > t_idx) { // 선행 스킬을 늦게 배웠으면 false 
				return false;
			}
			else if (idx == string::npos) { // 선행 스킬을 안 배운 경우
				return false;
			}
		}
		t_idx = idx;

	}
	return true;
}

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++) { // 스킬트리들 하나씩 조회
		string target = skill_trees[i];
		bool contain = false;

		for (int j = 0; j < target.size(); j++) {
			for (int k = 0; k < skill.size(); k++) {
				if (target.find(skill[k]) != string::npos) { // 포함 되어 있으면 내려가서 검사
					contain = true;
					break;
				}
			}   // end of for skill
		}   // end of for target
		if (!contain) { // 포함 되어 있지 않으면 정답 처리 후 다음 스킬트리로 이동
			answer++;
		}
		else if (check(target, skill)) {   // 포함 된 경우 확인
			answer++;
		}
	}   // end of for skill_trees
	return answer;
}