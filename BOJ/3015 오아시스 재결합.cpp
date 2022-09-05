#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack<pair<long, long>> stk;
	long long res = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		int cnt = 1;	// 어차피 저장되고 사용될떄는 캐스팅 되어 있어서 신경 안써도 될듯
		while (!stk.empty() && stk.top().first <= x) {
			res += stk.top().second;	// top을 뺴야되기 때문에 top을 기준으로 앞에 있는 값들의 영향받는 값의 숫자 저장

			if (stk.top().first == x) {		// 같은 숫자의 경우 그 전의 값 + 1의 숫자만큼 만나게 됨. 즉 1 ~ 중복 개수만큼 summation
				cnt = stk.top().second + 1;
			}
			stk.pop();
		}	// end of while
		if (!stk.empty()) {		// 남은 사람이 있으면 그 사람과도 짝이 지어짐. x와 top 사이에 숫자들이 다 빠졌다는 의미이므로
			res++;
		}
		stk.push({ x, cnt });
	}	// end of for

	cout << res << "\n";
	return 0;
}