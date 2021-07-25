#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	stack<char> stick;
	stick.push(input[0]);		// 처음은 무조건 들어가야 됨
	int sum = 0;
	for (int i = 1; i < input.size(); i++) {
		if (input[i] == '(') stick.push('(');	// ( 나오면 무조건 push
		else {									// ) 나오면 무조건 pop
			stick.pop();
			if (input[i - 1] == '(') {			// 바로 전이 ( 였으면 스틱 갯수 만큼 더해줌
				sum += stick.size();
			}
			else {				// 잘린 부분은 더해줬으나 원래 있던 막대기는 더해주지 못했기 때문에
				sum++;			// 레이저가 아니라면 막대기이므로 1씩 더해준다
			}
		}
	}
	cout << sum << "\n";
}