#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int num[8001];

int main() {
	int n;
	vector<int> vec;
	scanf("%d", &n);
	double sum = 0;
	
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
		sum += x;
		num[4000 + x]++;
	}
	sort(vec.begin(), vec.end());
	bool first = true;
	int most = -1;
	int most_num = -4001;
	vector<int> most_vec;

	for (int i = 0; i <= 8000; i++) {
		if (most < num[i]) {
			most_vec.clear();
			most_vec.push_back(i - 4000);
			most = num[i];
			first = true;
		}
		else if (most == num[i]) {
			most_vec.push_back(i - 4000);
			first = false;
		}
	}

	sort(most_vec.begin(), most_vec.end());
	double mean = sum / (double)n;
	printf("%0.f\n", mean);
	printf("%d\n", vec[n / 2]);
	if (!first) printf("%d\n", most_vec[1]);
	else printf("%d\n", most_vec[0]);
	printf("%d\n", vec[n - 1] - vec[0]);
}