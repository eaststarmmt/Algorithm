#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<bool> selected;

bool comb(int cnt, vector<string>& answer, vector<vector<string>>& tickets) {
	if (cnt == tickets.size()) {
		return true;
	}   // end of if

	for (int i = 0; i < tickets.size(); i++) {
		if (selected[i]) {
			continue;
		}
		if (tickets[i][0] == answer[cnt]) {  // 마지막 위치에 값과 출발점 같으면 진행
			selected[i] = true;
			answer.push_back(tickets[i][1]);    // 도착지점 표시
			if (comb(cnt + 1, answer, tickets)) {
				return true;
			}
			selected[i] = false;
			answer.pop_back();
		}
	}   // end of for

	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	selected = vector<bool>(tickets.size());
	sort(tickets.begin(), tickets.end());   // 정렬을 미리 해서 처음 나오는 값에서 멈춤
	answer.push_back("ICN");
	comb(0, answer, tickets);
	return answer;
}