#include<stdio.h>
using namespace std;

int main() {
	while (1) {
		int l, p, v;
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0) break;		// ��� 0 ������ ����
		int sum = 0;
		int cnt = 1;
		while (v > 0) {			
			if (v > p) {	// v �� ����� ũ�� v�� p��ŭ ���̸鼭 l ���� ��� ������
				v -= p;
				sum += l;
			}
			else {			// v �� ���� �۾��� ��Ȳ
				if(v > l) {	// l���� ũ�� l��ŭ ����
					sum += l;
					v = 0;
				}
				else {		// l���� ������ v�� ����
					sum += v;
					v = 0;
				}
				
			}
		}
		printf("Case %d: %d\n", cnt, sum);
		cnt++;
	}
}