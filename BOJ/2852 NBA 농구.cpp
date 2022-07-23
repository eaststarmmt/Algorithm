#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int A, B;
string prev_goal;

int time_to_int(string goal_time) {
	int temp_time;
	temp_time = stoi(goal_time.substr(0, 2)) * 60;
	temp_time += stoi(goal_time.substr(3));
	return temp_time;
}

void calc(int& sum, string goal_time) {
	sum += time_to_int(goal_time) - time_to_int(prev_goal);
}

string time_to_string(int& sum) {
	string minute = "00" + to_string(sum / 60);
	string sec = "00" + to_string(sum % 60);
	return minute.substr(minute.size() - 2) + ":" + sec.substr(sec.size() - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int asum = 0;
	int bsum = 0;
	for (int i = 0; i < N; i++) {
		int team;
		string goal_time;
		cin >> team >> goal_time;

		if (A > B) {
			calc(asum, goal_time);
		}
		else if (B > A) {	// 비기고 있는 경우는 계산 이뤄이지면 안됨
			calc(bsum, goal_time);
		}

		if (team == 1) {
			A++;
		}
		else {
			B++;
		}
		// prev가 먼저 있어야 계산이 가능하므로 다음번 계산부터 적용
		prev_goal = goal_time;
	}
	// 마지막은 적용이 안되었으므로 한번 더 진행
	if (A > B) {
		calc(asum, "48:00");
	}
	else if (B > A) {
		calc(bsum, "48:00");
	}

	cout << time_to_string(asum) << "\n";
	cout << time_to_string(bsum) << "\n";
	return 0;
}