#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> res;
char inequal[14];
bool selected[10];

bool checked(int before, int now, char ine) {
	if(ine == '<' && (before < now)) {
		return true;
	} else if (ine == '>' && (before > now)) {
		return true;
	} else {
		return false;
	}
}

void permutation(int cnt = 0, string num = "") {
	if(cnt == N + 1) {
		res.push_back(num);
		return;
	}	// end of if
	
	for(int i = 0; i <= 9; i++) {
		if(selected[i]) continue;
		if(cnt == 0 || checked(num[cnt - 1] - '0', i, inequal[cnt - 1])) {
			selected[i] = true;
			permutation(cnt + 1, num + to_string(i));
			selected[i] = false;
		}
	}	// end of for
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> inequal[i];
	}	// end of for
	
	permutation();
	sort(res.begin(), res.end());
	cout << res[res.size() - 1] << "\n";
	cout << res[0] << "\n";
	return 0;
}