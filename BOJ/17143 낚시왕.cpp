#include <bits/stdc++.h>
using namespace std;

struct Shark {
	int r, c, s, d, z;
	bool death;
};

vector<Shark> shark;
int _map[104][104], temp[104][104];
int R, C, M, res;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

void hunt(int c) {
	for(int r = 0; r < R; r++) {	// 위에서부터 상어 확인. 잡히면 바로 종료
		int idx = _map[r][c];	// 현 위치의 상어 인덱스. 없으면 0
		if(idx) {	// 상어가 있는 경우
			res += shark[idx].z;
			shark[idx].death = true;	// 잡았으니 죽은거 표시
			_map[r][c] = 0;
			return;
		}
	}	// end of for
}

void move() {
	memset(temp, 0, sizeof(temp));	// 이전 상어 이동 기록 삭제
	
	for(int i = 1; i <= M; i++) {
		int r = shark[i].r;
		int c = shark[i].c;
		int s = shark[i].s;
		int d = shark[i].d;
		int z = shark[i].z;
		
		if(shark[i].death) continue;	// 죽은 상어 무시
		
		int nr, nc;		// 다음 이동할 곳. while문 밖으로 빼서 계속 이용해야 됨
		
		while(1) {	// 입력 받을 때 s를 나머지 연산하여 최대 두번만 사용 됨
			nr = r + s * dr[d];
			nc = c + s * dc[d];
			if(nr >= 0 && nc >= 0 && nr < R && nc < C) break;	// 맵 안으로 들어오면 탈출
			
			if(d <= 1) {	// 상하 이동의 경우
				if(nr < 0) {	// 위에 벽에 닿은 경우
					s -= r;		// 앞으로 이동할 거리 - 벽까지의 거리
					r = 0;		// 현위치 0으로 조정
				} else {
					s -= R - 1 - r;
					r = R - 1;
				}
			} else {	// 좌우 이동
				if(nc < 0) {
					s -= c;
					c = 0;
				} else {
					s -= C - 1 - c;
					c = C - 1;
				}
			}
			
			d ^= 1;
		}	// end of while 이동
		// 이동 후 그 위치에 상어 있는지 확인
		if(temp[nr][nc]) {	// 상어가 이미 있는 경우
			if(shark[temp[nr][nc]].z < shark[i].z) {	// 새로 들어온 상어가 더 큰 경우
				shark[temp[nr][nc]].death = true;	// 원래 상어 죽이기
				temp[nr][nc] = i;	// 새로운 상어 인덱스 저장
			} else {	// 기존 상어가 더 큰 경우. 같은 경우는 없음
				shark[i].death = true;
				continue;
			}
		} else {	// 상어 없는 경우
			temp[nr][nc] = i;	// 현재 상어 인덱스 저장
		}
		shark[i].r = nr;	// 현재 상어 위치 저장
		shark[i].c = nc;
		shark[i].d= d;		// 상어 이동 중 방향도 바뀔수 있으므로 저장
	}
	memcpy(_map, temp, sizeof(temp));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> R >> C >> M;
	shark = vector<Shark>(1, Shark());	// 상어 인덱스를 1부터 쓰기 위해. 0부터 하면 map에 상어가 없는 경우와 0번 인덱스를 구분 못함
	for(int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		r--; c--; d--;	// 맵을 0,0 부터 쓰기 위해. 방향은 xor 이용하면 0과 1, 2와 3을 변환할 수 있음
		
		// 이동 가능 칸 수는 끝에서 끝인 경우 C - 1. 
		// 인덱스가 줄어드는 지점을 확장해서 보면 (C - 1) * 2만큼 이동 가능. 
		// 이 숫자로 나눈 나머지의 자리에 멈춘다는 의미
		s %= d <= 1 ? (R - 1) * 2: (C - 1) * 2;
		shark.push_back({r, c, s, d, z});
		_map[r][c] = i;
	}
	
	for(int c = 0; c < C; c++) {	// 낚시왕 이동
		hunt(c);
		move();
	}
	
	cout << res << "\n";
	return 0;
}