#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct balloon {
	int index, num;
};

bool cmp(balloon a, balloon b) {
	return a.num < b.num;
}
int solution(vector<int> a) {
	int answer = 2;
	if (a.size() <= 2) return a.size();
	vector<balloon> balloons;
	for (int i = 0; i < a.size(); i++) {
		balloons.push_back({ i, a[i] });  // index와 숫자 저장
	}
	sort(balloons.begin(), balloons.end(), cmp);
	// 가장 작은 값 두개로 상한선 하한선 잡음. 이 사이에 값 들어오면 살아남을 수 없음
	int lower = balloons[0].index < balloons[1].index ? balloons[0].index : balloons[1].index;
	int upper = balloons[0].index > balloons[1].index ? balloons[0].index : balloons[1].index;
	// 양 옆에 작은숫자가 없으면 살 수 있음
	for (int i = 2; i < balloons.size(); i++) {
		if (balloons[i].index > lower && balloons[i].index < upper)  // 사이에 들어왔으면 무조건 터짐
			continue;
		if (balloons[i].index < lower)   // 인덱스가 하한선 보다 작으면 하한선 변경
			lower = balloons[i].index;
		else if (balloons[i].index > upper)  // 상한선보다 크면 상한선 변경
			upper = balloons[i].index;
		answer++;       // contiune에 걸러지지 않았으면 살아남았으므로 카운팅
	}
	return answer;
}