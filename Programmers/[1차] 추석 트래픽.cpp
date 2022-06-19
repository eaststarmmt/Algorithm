#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<pair<int, bool>> infos;  //시간, 시작(true) or 끝(false)

bool cmp(pair<int, bool> a, pair<int, bool> b) {
	if (a.first == b.first) {
		if (a.second) return a.second > b.second;    // 시작이 우선시 되도록
	}

	return a.first < b.first;
}

void setTime(string time, string period) {
	int start, end;
	start = end = 0;
	stringstream stream(time);
	string temp;
	int calc = 60 * 60 * 1000;  // hour to ms

	while (getline(stream, temp, ':')) { // : 기준으로 분해해서 ms 단위로 변환
		end += stod(temp) * calc;       // 마지막에 초가 소수 단위이므로 stod 사용
		calc /= 60;              // 분, 초 단위로 바꾸기 위함
	}   // end of while

	start = end - stod(period.substr(0, period.size() - 1)) * 1000 + 1; // 처리 시간이 초 단위이므로 1000을 곱해줘야 됨
	end += 999;     // 예제 2번처럼 동시에 겹치는것을 묻는 것이 아닌 any 시점에 1초를 기준으로 몇개가 들어왔느냐를 묻는 문제. 끝 시간에 999를 더하면 1초 범위의 계산이 가능해짐
	infos.push_back({ start, true });
	infos.push_back({ end, false });

}

void setInfo(string s) {
	stringstream stream(s);
	string info[3];
	int idx = 0;
	while (stream >> info[idx++]) {}
	setTime(info[1], info[2]);  // 0번에 저장된 날짜 정보는 의미 없음
}
int solution(vector<string> lines) {
	int answer = 0;
	for (int i = 0; i < lines.size(); i++) {
		setInfo(lines[i]);
	}
	sort(infos.begin(), infos.end(), cmp);
	int cnt = 0;
	for (pair<int, bool> i : infos) {
		if (i.second) cnt++;
		else cnt--;
		answer = cnt > answer ? cnt : answer;
	}

	return answer;
}