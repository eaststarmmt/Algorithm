#include<stdio.h>
#include<algorithm>
using namespace std;

int num[10001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		num[x]++;
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < num[i]; j++) {
			printf("%d\n", i);
		}
	}
}