#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) printf("%d\n", vec[i]);

}