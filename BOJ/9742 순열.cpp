// 문제의도는 라이브러리가 아닌 직접 구현해라 같은데.... 
// 답을 뽑는건 성공 했으나 재귀를 너무 깊이 들어가서 메모리 초과가 나는걸 극복 못함
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string input;
	int n;
	while (!(cin >> input >> n).eof()) {		// 입력을 받았으면 실행
		bool output = false;					// 만약 경우의 수가 n번을 넘어가면 output은 끝까지 false로 남아있음
		string result = input;
		int i = 0;
		do {									// do while을 사용하는 이유는 루프가 처음부터 next_permutation에 들어가야 되기 때문
			i++;
			if (i == n) {				
				cout << input << " " << n << " = " << result << "\n";
				output = true;
			}
		} while (next_permutation(result.begin(), result.end()));
		if (!output)
			cout << input << " " << n << " = No permutation\n";
	}
}