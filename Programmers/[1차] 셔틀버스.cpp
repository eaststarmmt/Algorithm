#include <string>
#include <vector>
#include <algorithm>
#define FIRST 60 * 9    // 9시
using namespace std;


string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	vector<int> time;
	for (int i = 0; i < timetable.size(); i++) { // 계산하기 편하게 전부 
		time.push_back(stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3)));
	}
	sort(time.begin(), time.end());

	int now = FIRST;
	int idx = 0;
	int cnt = 0;					// 버스에 탈 수 있는 최대 사람 수 넘었는지 확인
	for (int i = 0; i < n; i++, now += t) {
		cnt = 0;
		for (int j = idx; j < time.size(); j++) {
			if (now >= time[idx]) {	// 도착시간 전에 도착한 크루들 탑승
				cnt++;
				idx++;
				if (cnt == m) {
					break;
				}
			}
			else {		// 도착 시간이 더 늦으면 시간의 경과가 필요함
				break;
			}
		}
	}
	int res;
	idx--;
	now -= t;	// for문이 끝나더라도 뒤에 계산식은 계산 됨
	if (cnt == m) {	// 마지막 버스에 사람 꽉 찬 경우
		res = time[idx] - 1;
	}
	else {		// 마지막 버스에 자리 남은 경우
		res = now;
	}
	string hour;
	if ((res / 60) < 10) {
		hour = "0" + to_string(res / 60);
	}
	else {
		hour = to_string(res / 60);
	}
	string min = to_string(res % 60);

	if ((res % 60) < 10) {
		min = "0" + to_string(res % 60);
	}
	else {
		min = to_string(res % 60);
	}
	answer = hour + ":" + min;
	return answer;
}