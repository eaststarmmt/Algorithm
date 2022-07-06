#include <iostream>
using namespace std;

int car[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;
		for (int j = start + 1; j <= end; j++) {
			car[j]++;
		}
	}

	int answer = 0;
	for (int i = 1; i <= 100; i++) {
		if (car[i] == 1) {
			answer += A;
		}
		else if (car[i] == 2) {
			answer += B * car[i];
		}
		else if (car[i] == 3) {
			answer += C * car[i];
		}
	}
	cout << answer << endl;
}