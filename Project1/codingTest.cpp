#include<iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		string input;
		cin >> input;
		string repeat;
		int cnt = 0;
		int start;
		for (int i = 1; i < input.size(); i++) {
			if (input[i] == input[0]) {			// 첫 문자와 같으면 우선 반복 의심
				repeat = input.substr(0, i);	// 0번부터 현재위치 직전까지 잘라냄
				if (i * 2 <= 30 && repeat == input.substr(i, i)) {	// 다음번에도 반복되는지 확인
					cnt = i;	// i값이 잘라낸 문자의 길이이므로 출력
					break;
				}
			}
		}
		cout << "#" << test << " "<< cnt<< "\n";
	}
}