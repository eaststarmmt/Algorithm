#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#define endl "\n"
using namespace std;
bool button[10] = { true,true,true,true,true,true,true,true,true,true };
int N, M;
int ans;
int len;	// 길이 계속 반환해주는 방법 사용
bool checked(int x) {
	string check = to_string(x);	// x를 문자열로 변환
	len = check.length();
	for (int i = 0; i < check.size(); i++) {
		if (!button[check[i] - '0']) return false;	// 하나라도 안눌리면 의미 없음
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		button[b] = false;
	}
	ans = abs(100 - N);	// 차이만큼 무조건 누르는 방법
	for (int i = 0; i <= 1000000; i++) {		// 일단 버튼 시작위치 다 찍어보기. 이거 더 큰 숫자 찍고 내려오는 경우때문에 1000000 잡아야 됨. 더 큰 숫자는 밑에서 오는게 더 빠르므로 의미 없음
		if (checked(i)) {	// i 가 버튼 눌리는지 확인
			int x = abs(N - i) + len;
			ans = x < ans ? x : ans;
		}
	}
	cout << ans << endl;
}