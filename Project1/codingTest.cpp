#include<iostream>
#include<vector>
#include<string>
#define endl "\n"
using namespace std;

int N, K, maxReadable;
vector<string> word;

void comb(int learn, int cnt, int start) {
	if (cnt == K) {	// K개 만큼 배웠을때
		int readable = 0;	// 현재 배운 단어에서 읽을 수 있는 단어 개수
		for (int i = 0; i < word.size(); i++) {	// 저장된 단어 개수만큼 반복
			int check = 0;						// 단어 비트로 바꿔서 저장할 변수
			for (int j = 0; j < word[i].size(); j++) {	// 단어에서 글자 하나하나 확인
				check |= 1 << word[i][j] - 'a';		// 해당 글자가 포함된 곳 1로 표시
			}
			if ((learn & check) == check) {		// 배운 글자와 단어에 글자를 and 연산해서 그 값이 단어와 같으면 읽을 수 있음
				readable++;
			}
		}
		maxReadable = readable > maxReadable ? readable : maxReadable;	// 최대값 갱신
		return;
	}
	for (int i = start; i < 26; i++) {
		if (i == 'a' || i == 'c' || i == 'i' || i == 'n' || i == 't')	// 반드시 포함되어야 하는 단어
			continue;
		int x = 0;	
		x |= 1 << i;		
		if (x & learn) continue;		// i 가 learn에 포함 되어 있으면 다음 단어 확인
		comb(learn | (1 << i), cnt + 1, i + 1);		// 새로운 단어 배운 후 재귀. 이렇게 하면 다음 단어 선택때 1을 안꺼도 됨
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		word.push_back(s);
	}	// N 개의 단어 저장

	if (K < 5) {
		cout << 0 << endl;
		return 0;
	}

	int learn = 0;
	learn |= 1;	// 'a'
	learn |= 1 << 'c' - 'a';
	learn |= 1 << 'i' - 'a';
	learn |= 1 << 'n' - 'a';
	learn |= 1 << 't' - 'a';

	comb(learn, 5, 0);	// 처음 접두사 접미사에 포함되는 단어 5개는 들고 시작
	cout << maxReadable << endl;
}