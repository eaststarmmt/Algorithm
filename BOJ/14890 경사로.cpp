#include <iostream>
using namespace std;

int N, L;
int map[104][104], map_rot[104][104];

int check(int map[104][104]) {	// 배열은 참조형 안됨. 포인터로만 사용 가능
	int res = 0;
	int cnt;
	for (int i = 0; i < N; i++) {
		cnt = 1;	// 일단 자기 자신. 한개는 무조건 있음
		int j;
		for (j = 1; j < N; j++) {
			if (map[i][j - 1] == map[i][j]) {
				cnt++;
			}
			else if ((map[i][j - 1] + 1 == map[i][j]) && (cnt >= L)) {	// 오르막길. L만큼 같은 길이 확보 되었으면 초기화
				cnt = 1;
			}
			else if ((map[i][j - 1] == map[i][j] + 1) && (cnt >= 0)) {	// 내리막길 -L로 세팅해서 0이 되었으면 패스. cnt를 1씩 증가 시키므로 이렇게 하면 일관성 있게 카운팅 가능
				cnt = -L + 1;
			}
			else {	// 나머지의 경우 안되는 경우
				break;
			}
		}	// end of for j
		if (j == N && cnt >= 0) {	// 오르막의 경우는 체크가 되었을텐데 내리막은 아직 진행중이면 체크가 안되었을수 있음
			res++;
		}
	}	// end of for i

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			map_rot[j][i] = map[i][j];	// 행 기준으로 열을 확인하는 것이 익숙하기에 대칭된 map을 만듬
		}	// end of for j
	}	// end of for i

	int res = check(map);
	res += check(map_rot);
	cout << res << "\n";
	return 0;
}