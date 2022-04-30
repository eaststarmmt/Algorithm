#include <string>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
int answer;
int R, C;   // 사람 수, 속성 수
vector<string> candidate;
bool uniqueCheck(string select, vector<vector<string>>& relation) {
	set<string> unique;
	for (int i = 0; i < R; i++) {
		string temp;
		for (int j = 0; j < select.size(); j++) {    // select에 들어있는 인덱스 조합으로 값 만들어서 중복성 체크
			temp += relation[i][select[j] - '0'];
		}   // end of for j
		if (unique.find(temp) != unique.end()) { // 이미 이전에 값 있으면 유일성 깨짐
			return false;
		}
		unique.insert(temp);    // 중복 확인을 위해 없다면 결과값 저장
	}   // end of for i
	return true;
}

// 조건을 하나씩 늘리는 형태이므로 이미 들어있는 조합을 확인하려는 조건에 포함되는지 체크
bool minCheck(string select) {
	for (int i = 0; i < candidate.size(); i++) {
		int cnt = 0;    // 기존의 후보키의 길이와 맞는지 체크하기 위한 용도
		for (int j = 0; j < candidate[i].size(); j++) {
			if (select.find(candidate[i][j]) != string::npos) {
				cnt++;
			}
		}
		// candidate[i] 의 모든 원소의 개수랑 일치하는 경우. 즉 포함된 경우는 최소성이 깨짐
		if (cnt == candidate[i].size()) return false;
	}
	return true;
}

void comb(int start, string select, int level, vector<vector<string>>& relation) {
	if (select.size() == level) {
		if (uniqueCheck(select, relation)) { // 유일성 체크
			if (minCheck(select)) {    // 최소성 체크
				candidate.push_back(select);
				answer++;
			}
		}
		return;
	}

	for (int i = start; i < C; i++) {
		comb(i + 1, select + to_string(i), level, relation);
	}   // end of for
}

int solution(vector<vector<string>> relation) {
	R = relation.size();
	C = relation[0].size();
	for (int level = 1; level <= C; level++) {  // 조건 한 개씩 늘려가며 체크
		comb(0, "", level, relation);
	}
	return answer;
}