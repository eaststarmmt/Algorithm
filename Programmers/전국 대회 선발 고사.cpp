#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
	int i, r;
	bool a;
};

bool cmp(Info a1, Info a2) {
	if (a1.a == a2.a) {
		return a1.r < a2.r;
	}
	return a1.a > a2.a;
}

int solution(vector<int> rank, vector<bool> attendance) {
	int answer = 0;
	vector<Info> v;
	for (int i = 0; i < rank.size(); i++) {
		v.push_back({ i, rank[i], attendance[i] });
	}

	sort(v.begin(), v.end(), cmp);

	answer = v[0].i * 10000 + v[1].i * 100 + v[2].i;
	return answer;
}