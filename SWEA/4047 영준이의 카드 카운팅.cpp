#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int S[14], D[14], H[14], C[14];


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {

		memset(S, 0, sizeof(S));	// 0으로 초기화
		memset(D, 0, sizeof(D));
		memset(H, 0, sizeof(H));
		memset(C, 0, sizeof(C));
		int s = 13, d = 13, h = 13, c = 13;		// 13에서 빼줘서 부족한 카드 개수 구함
		string input;
		cin >> input;
		bool flag = true;

		for (int i = 0; i < input.size(); i += 3) {
			switch (input[i]) {
			case 'S':
				if (input[i + 1] == '0') {		// 처음 들어온 숫자면 ++, 아니면 flag false로 표시
					if (S[input[i + 2] - '0'] == 0) S[input[i + 2] - '0']++;
					else flag = false;		
				}
				else {
					if (S[input[i + 2] - '0' + 10] == 0) S[input[i + 2] - '0' + 10]++;
					else flag = false;
				}
				if (flag) s--;					// 중복 없는 경우에 필요한 카드 개수 감소
				break;
			case 'D':
				if (input[i + 1] == '0') {
					if (D[input[i + 2] - '0'] == 0) D[input[i + 2] - '0']++;
					else flag = false;
				}
				else {
					if (D[input[i + 2] - '0' + 10] == 0) D[input[i + 2] - '0' + 10]++;
					else flag = false;
				}
				if (flag) d--;
				break;
			case 'H':
				if (input[i + 1] == '0') {
					if (H[input[i + 2] - '0'] == 0) H[input[i + 2] - '0']++;
					else flag = false;
				}
				else {
					if (H[input[i + 2] - '0' + 10] == 0) H[input[i + 2] - '0' + 10]++;
					else flag = false;
				}
				if (flag) h--;
				break;
			case 'C':
				if (input[i + 1] == '0') {
					if (C[input[i + 2] - '0'] == 0) C[input[i + 2] - '0']++;
					else flag = false;
				}
				else {
					if (C[input[i + 2] - '0' + 10] == 0) C[input[i + 2] - '0' + 10]++;
					else flag = false;
				}
				if (flag) c--;
				break;
			}
		}
		if (!flag) cout << "#" << test << ' ' << "ERROR" << "\n";
		else cout <<"#" << test << ' ' << s << ' ' << d << ' ' << h << ' ' << c << "\n";
	}
}








/*
3
S01D02H03H04
H02H10S11H02
S10D10H10C01
*/