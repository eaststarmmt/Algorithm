#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		string input[5];		// 입력이 5개라고 정해졌기 때문에 string 5개 받음
		int maxLenghth = -1;	// 가장 긴 가로줄 체크
		for (int i = 0; i < 5; i++) {
			cin >> input[i];
			int x = input[i].size();	// size() 함수가 int 타입이 아니므로 따로 int로 저장해놓고 비고해야됨
			maxLenghth = max(x, maxLenghth);
		}
		cout << "#" << test << " ";
		for (int i = 0; i < maxLenghth; i++) {		// 가로줄 최대 길이 까지
			for (int j = 0; j < 5; j++) {		
				int x = input[j].size();			
				if (x > i) cout << input[j][i];		// string 길이가 초과되지 않았으면 출력
			}
		}
		cout << "\n";
	}
}