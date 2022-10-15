#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> multi;
int items[104];
int N, K, res;
bool visited[104];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> items[i];
	}	// end of for input

	for (int i = 0; i < K; i++) {
		int item = items[i];

		if (visited[item]) {
			continue;
		}

		if (multi.size() != N) {
			multi.push_back(item);
			visited[item] = true;
			continue;
		}

		int last = 0;
		int value;	// 안나오더라도 무조건 갱신 됨
		for (int x : multi) {
			int idx = 1e9;	// 끝까지 없으면 10억 유지
			for (int j = i + 1; j < K; j++) {
				// 마지막으로 사용 되는 item 제거해야 됨
				if (x == items[j]) {
					idx = j;
					break;
				}
			}	// end of for j
			// 현재 인덱스랑 지금까지 나온 제일 뒤에 나오는 인덱스 비교
			if(idx > last) {
				last = idx;
				value = x;
			}
		}	// end of for multi

		multi.erase(find(multi.begin(), multi.end(), value));
		visited[value] = false;

		multi.push_back(item);
		visited[item] = true;
		res++;
	}

	cout << res << "\n";
	return 0;
}