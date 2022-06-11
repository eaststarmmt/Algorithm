#include <string>
#include <vector>
using namespace std;
vector<int> lion, apeach;
int maxDif = -1;
int N;

bool check(vector<int>& temp) {
	for (int i = 10; i >= 0; i--) {
		if (lion[i] == 0 && temp[i] == 0) continue;
		else if (temp[i] > lion[i]) return true;
		else if (temp[i] == lion[i]) continue;
		else if (temp[i] < lion[i]) return false;
	}
	return false;
}

void calc(vector<int>& temp) {
	int apeach_score = 0;
	int lion_score = 0;
	for (int i = 0; i < 11; i++) {
		if (temp[i] > apeach[i]) {
			lion_score += 10 - i;
		}
		else if (apeach[i] != 0) {
			apeach_score += 10 - i;
		}
	}   // end of for
	int dif = lion_score - apeach_score;
	if (dif > 0) {              // 라인언이 이김
		if (dif < maxDif) return;    // 차이 최대 아니면 무시
		else if (dif == maxDif) {   // 같을 경우 가장 낮은 화살 비교
			if (!check(temp)) {
				return;
			}
		}
		maxDif = dif;
		lion = temp;
	}
}

void comb(int start, int cnt, vector<int> temp) {
	if (cnt == N) {
		calc(temp);
		return;
	}

	for (int i = start; i < 10; i++) {
		if (N - cnt > apeach[i]) {
			temp[i] += apeach[i] + 1;
			comb(start + 1, cnt + apeach[i] + 1, temp);
			temp[i] -= apeach[i] + 1;
		}
	}
	if (cnt < N) {      // 끝까지 갔는데 남은경우 계산 안되는 현상 방지
		temp[10] += N - cnt;
		comb(start, N, temp);
	}
}

vector<int> solution(int n, vector<int> info) {
	vector<int> answer;
	apeach = info;
	N = n;
	vector<int> temp(11);
	comb(0, 0, temp);
	if (lion.size() == 0) {
		answer.push_back(-1);
	}
	else {
		answer = lion;
	}
	return answer;
}