#include <string>
#include <vector>
#include <set>
using namespace std;
int answer;
char selected[7];
bool isSelected[7];
bool prime[10000000];   // false가 소수 true가 합성수
int num_size;
set<int> num_set;
// powerset 개념으로 모든 경우의 수를 num_set이라는 set에 저장
void powerset(string& numbers, int cnt) {
	if (cnt == num_size) {
		string temp;
		for (int i = 0; i < num_size; i++) {
			temp += selected[i];
			num_set.insert(stoi(temp));
		}   // end of for
		return;
	}   // end of if

	for (int i = 0; i < num_size; i++) { // 순열
		if (isSelected[i]) continue;
		selected[cnt] = numbers[i];
		isSelected[i] = true;
		powerset(numbers, cnt + 1);
		isSelected[i] = false;
	}
}

void eratos() {
	prime[0] = true;    // 소수가 아니므로 합성수 처리해서 답에 안걸리게 함
	prime[1] = true;
	for (int i = 2; i < 10000; i++) {
		if (prime[i]) continue;
		for (int j = i * i; j < 10000000; j += i) {
			prime[j] = true;
		}
	}
}

void getAnswer(string& numbers, int& answer) {
	for (auto i : num_set) { // set에 들어있는 숫자가 소수일때마다 카운팅
		if (!prime[i]) {
			answer++;
		}
	}
}

int solution(string numbers) {
	eratos();   // 소수 구하기
	num_size = numbers.size();  // 숫자가 몇자리인지 크기 계산
	powerset(numbers, 0);
	getAnswer(numbers, answer);
	return answer;
}