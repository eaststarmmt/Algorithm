#include<iostream>
#define endl "\n"
using namespace std;

int R, C, B;
int map[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> B;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	int resHeight = 9999;
	int resTime = 1e9;
	for (int height = 0; height <= 256; height++) {
		int inven = B;							// B�� �ǵ帮�� ���� ���꿡�� ������ ���� �� ����
		int time = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				// ���ϴ� ���̺��� ���� ���
				if (map[i][j] > height) {			// ���� ���� * 2 ��ŭ�� �ð��� �ҿ��
					int x = map[i][j] - height;
					inven += x;
					time += 2 * x;
				}
				else if(map[i][j] < height){		// ���� ���� ��ŭ�� �ð��� �ҿ��
					int x =  height - map[i][j];
					inven -= height - map[i][j];
					time += x;
				}
			}
		}
		if (inven >= 0 && resTime >= time) {	// ���̴� ���� �������ϱ� �ð� ������ �����ϸ� ���� �ð��϶� ���� ���̰� ����
			resTime = time;
			resHeight = height;
		}
	}
	cout << resTime << ' ' << resHeight << endl;
}