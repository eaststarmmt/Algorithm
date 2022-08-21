#include <string>
#include <vector>
#include <sstream>
using namespace std;

int video[360000];

int string_to_int(string s) {   // 시간값들 int 타입으로 변환
	stringstream stream(s);
	string temp;
	int time = 0;
	int oper = 3600;
	while (getline(stream, temp, ':')) {
		time += stoi(temp) * oper;
		oper /= 60;
	}

	return time;
}

string int_to_string(int t) {
	string time;
	int hour = t / 3600;
	t %= 3600;
	int min = t / 60;
	int sec = t % 60;
	time += hour > 9 ? to_string(hour) : "0" + to_string(hour);
	time += ":";
	time += min > 9 ? to_string(min) : "0" + to_string(min);
	time += ":";
	time += sec > 9 ? to_string(sec) : "0" + to_string(sec);

	return time;
}

void save_log(int logs[]) {     // 몇명 시청하고 있는지 기록
	for (int i = logs[0] + 1; i <= logs[1]; i++) {   // 누적 재생 시간이므로 시작 시간은 누적이 안됨
		video[i]++;
	}   // end of for
}

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";
	int size = string_to_int(play_time);
	int ad_size = string_to_int(adv_time);
	for (int i = 0; i < logs.size(); i++) {
		stringstream stream(logs[i]);
		string temp;
		int log[2];     // 시작시간과 종료 시간 저장
		int idx = 0;

		while (getline(stream, temp, '-')) {
			log[idx++] = string_to_int(temp);
		}   // end of while

		save_log(log);
	}

	long long ad_start = 1;
	long long max_play = 0;
	for (int i = 1; i <= ad_size; i++) { // 처음부터 재생했을때 재생 시간 값 저장
		max_play += (long long)video[i];
	}   // end of for

	long long now_play = max_play;

	for (int i = 2; i <= size - ad_size + 1; i++) {   // +1이 붙는 이유는 누적 재생 개념을 1초 뒤에 측정되는 형식으로 잡았기 때문
		now_play += (long long)video[ad_size + i - 1] - video[i - 1];   // 이전 1초 빼고 다음 1초 더하고
		if (now_play > max_play) {   // 부등호 안붙이면 같은 값일때 먼저 일어난 값으로 저장됨
			max_play = now_play;
			ad_start = i;
		}
	}

	answer = int_to_string(ad_start - 1);   // 누적 시간으로 계산 되었기 때문에 시작 시간을 찾으려면 1을 빼야됨

	return answer;
}