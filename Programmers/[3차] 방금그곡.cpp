#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
struct Info {
	string music, name;
	int time;
};
string input[4];
string sharp_list[] = { "C#", "D#", "F#", "G#", "A#" };
string sharp_replace[] = { "c", "d", "f", "g", "a" };
bool cmp(Info a, Info b) {
	return a.time > b.time;
}

void repeat(string& music, string target, int play_time) {  // ������ ª�Ƽ� �ݺ��ϴ� ���
	int queotient = play_time / target.size();   // �ݺ� Ƚ��
	int remainder = play_time % target.size();   // �ݺ��ϰ� ���� �ð�
	for (int i = 0; i < queotient; i++) {
		music += target;
	}
	music += target.substr(0, remainder);
}

// , ������ ����
void split(int& play_time, string& name, string& music, string& music_info) {
	stringstream sstream(music_info);
	int i = 0;
	while (getline(sstream, music_info, ',')) {
		input[i++] = music_info;
	}   // end of while
	int hour = stoi(input[1].substr(0, 2)) - stoi(input[0].substr(0, 2));
	int min = stoi(input[1].substr(3)) - stoi(input[0].substr(3));
	play_time = hour * 60 + min;
	name = input[2];
	if (play_time <= input[3].size()) {  // ��� �ð��� �� ª�ų� ���� ���
		music = input[3].substr(0, play_time);
	}
	else {                // ��� �ð��� �� �� ���
		repeat(music, input[3], play_time);
	}
}

void removeSharp(string &m) {   // # �� �ֵ� �� �ҹ��ڷ� �ٲ��ֱ�
	for (int i = 0; i < 5; i++) {
		int start;
		while ((start = m.find(sharp_list[i])) != string::npos) {
			m.replace(start, 2, sharp_replace[i]);
		}   // end of while
	}
}

string solution(string m, vector<string> musicinfos) {
	string answer = "(None)";
	vector<Info> info;
	removeSharp(m);
	for (int i = 0; i < musicinfos.size(); i++) {    // �ʿ��� ���� ����
		string music_info = musicinfos[i];
		removeSharp(music_info);
		int play_time;
		string name, music;
		split(play_time, name, music, music_info);
		info.push_back({ music, name, play_time });
	}   // end of for

	sort(info.begin(), info.end(), cmp);    // ���̷� �����Ͽ� ó�� ã�� ���ڸ� �ٷ� �������� ó��
	for (int i = 0; i < info.size(); i++) {
		int index = info[i].music.find(m);
		if (index != string::npos) {     // m �� ���Ե� ���ڿ� ã��
			answer = info[i].name;
			break;
		}
	}
	return answer;
}