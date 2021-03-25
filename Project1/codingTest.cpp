#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int zcnt, ocnt;
int z[41];
int o[41];

int main() {
	int t;
	scanf("%d", &t);
	vector<int> vec;
	z[0] = 1;
	o[1] = 1;
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		for (int j = 2; j <= n; j++) {
			if (o[j] != 0 || z[j] != 0) 
				continue;
			z[j] = z[j - 1] + z[j - 2];
			o[j] = o[j - 1] + o[j - 2];
		}
		printf("%d %d \n", z[n], o[n]);
	}
}