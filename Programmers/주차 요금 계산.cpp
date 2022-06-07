#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

struct Info {
	string in, num;
	int time = 0;
};

bool cmp(Info a, Info b) {
	return a.num < b.num;
}
unordered_map<string, Info> map;    // 차량번호, 주차 정보들

void getRecord(string record, vector<int>& fees) {
	stringstream stream(record);
	Info i;
	string num, time, io;
	stream >> time; // 시간
	stream >> num;
	stream >> io;
	i.num = num;
	if (io == "IN") {    // 들어온 경우
		i.in = time;
		i.time = map[num].time;	// 안넣어주면 시간 0으로 초기화 됨
		map[num] = i;
	}
	else {    // 나간 경우
		int hour = stoi(time.substr(0, 2)) - stoi(map[num].in.substr(0, 2));
		int minute = stoi(time.substr(3, 2)) - stoi(map[num].in.substr(3, 2));
		if (minute < 0) {
			minute += 60;
			hour--;
		}
		map[num].time += hour * 60 + minute;
		map[num].in = "";   // 시간 값 없애서 안나간 경우 다시 계산해야 됨
	}
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	for (int i = 0; i < records.size(); i++) {
		string record = records[i];
		getRecord(record, fees);
	}   // end of for
	vector<Info> result;
	for (auto it = map.begin(); it != map.end(); it++) {  // 나간 시간 표시 안된 차량들 처리
		Info i = it->second;
		if (i.in != "") {
			int hour = 23 - stoi(map[i.num].in.substr(0, 2));
			int minute = 59 - stoi(map[i.num].in.substr(3, 2));
			it->second.time += hour * 60 + minute;
		}
		result.push_back(it->second);
	}   // end of for map

	sort(result.begin(), result.end(), cmp);    // 주차 번호로 정렬

	for (int i = 0; i < result.size(); i++) {
		int time = result[i].time;
		int sum = fees[1];
		if (time > fees[0]) {
			sum += ceil((time - fees[0]) / (double)fees[2]) * fees[3];  // double 처리 안하면 소수점 인식 안하고 그냥 버려짐
		}
		answer.push_back(sum);
	}
	return answer;
}