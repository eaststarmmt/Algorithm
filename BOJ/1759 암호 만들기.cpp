#include<stdio.h>
#include<algorithm>
using namespace std;

int N, C;
char input[15];
char output[15];
void comb(int cnt, int vowel, int consonant, int start) {
	if (cnt == N) {								
		if (vowel >= 1 && consonant >= 2) {		// 개수 채워지고 자음 한 개 이상 모음 두 개 이상 되면 출력
			for (int i = 0; i < cnt; i++) {
				printf("%c", output[i]);
			}
			printf("\n");
		}
		return;
	}

	for (int i = start; i < C; i++) {
		output[cnt] = input[i];
		if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')	// 모음인 경우
			comb(cnt + 1, vowel + 1, consonant, i + 1);
		else																							// 자음인 경우
			comb(cnt + 1, vowel, consonant + 1, i + 1);
	}

}

int main() {

	scanf("%d %d", &N, &C);
	for (int i = 0; i < C; i++) {
		scanf(" %c", &input[i]);
	}
	
	sort(input, input + C);			// 사전순으로 출력하기 위해 미리 sort
	comb(0, 0, 0, 0);
}