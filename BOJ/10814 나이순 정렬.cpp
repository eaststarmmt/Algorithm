#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define endl "\n"
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<string>> input(201);	// counting sort를 위한 vector. 200살 까지 되므로 201개 선언
	for (int i = 0; i < N; i++) {
		int x;
		string s;
		cin >> x >> s;			
		input[x].push_back(s);	// 나이가 x인 사람들이 등록된 순서대로 배치됨
	}
	int cnt = 0;
	for (int i = 1; i < 201; i++) {	// 1살부터 200살 까지 확인
		if (input[i].size() == 0) continue;	// 해당 나이의 사람이 없으면 건너뛰기
		for (string s : input[i]) {
			cout << i << " " << s << endl;	
			cnt++;
		}
		if (cnt == N) return 0;	// N명 나왔으면 뒤에 사람 없으므로 종료
	}
}