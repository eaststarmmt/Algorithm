#include<cstdio>
#include<vector>
using namespace std;

int N;
int Min = 1e9;
int result;
vector<int> v;
vector<int> ans;

void backtracking(int k)
{
	if (v.size() >= Min) return;

	if (k == N)
	{
		if (v.size() < Min)
		{
			Min = v.size();
			ans.clear();
			for (int i = 0; i < v.size(); i++)
				ans.push_back(v[i]);
		}
	}

	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (k + v[i] <= N)
		{
			v.push_back(k + v[i]);
			backtracking(k + v[i]);
			v.pop_back();
		}
	}
}

int main()
{
	while (true) {
		v.clear();
		ans.clear();
		Min = 1e9;
		scanf("%d", &N);
		if (N == 0) break;
		v.push_back(1);
		backtracking(1);

		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
}