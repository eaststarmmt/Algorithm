#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<sstream>
#include<vector>
#define endl "\n"
typedef long long ll;
using namespace std;

unordered_map<string, int> dictionary;
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if(s.size() >= 3)	// 크기 3보다 작으면 그냥 넣으면 됨
			sort(s.begin() + 1, s.end() - 1);	// 처음 단어랑 끝 단어를 정렬해서 하나로 인식하게 함
		dictionary[s]++;	// 해당 단어 카운팅. 중간만 바뀐애들이 사전에 있을 수도 있기 때문에
	}	// end of dictionary

	cin >> M;
	cin.ignore();	// 남아있는 \n 날려줘야 됨
	
	for (int i = 0; i < M; i++) {
		string input;
		ll res = 1;
		getline(cin, input);	// 한 줄 단위 입력
		stringstream stream(input);	// 받은 문자열 stream에 넣기
		vector<string> wordCheck;	// 공백 기준 분리된 단어 넣을 벡터
		while(getline(stream, input, ' ')) {	// 공백기준으로 자를 수 있음
			if(input.size() >= 3)		// 크기 3보다 작으면 그냥 넣으면 됨
				sort(input.begin() + 1, input.end() - 1);
			
			wordCheck.push_back(input);	// 체크할 단어 넣어놓기
		}	// end of one line sentence
		bool flag = false;
		for (int word = 0; word < wordCheck.size(); word++) {
			if (dictionary[wordCheck[word]] > 0) {
				res *= dictionary[wordCheck[word]];
				flag = true;
			}
		}
		if (flag)	// 사전에 단어가 한번이라도 나왔을 때
			cout << res << endl;
		else		// 사전에 단어가 없었을 때
			cout << 0 << endl;
	}	// end of whole sentence
	
}