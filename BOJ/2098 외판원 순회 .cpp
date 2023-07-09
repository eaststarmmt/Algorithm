#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 1e9
using namespace std;

int N, dp[16][1 << 16], dist[20][20];

int tsp(int cur, int visited) {     // cur은 현위치, visited는 비트마스킹으로 1이면 방문 0이면 방문 안함
    if(visited == (1 << N) - 1) {   // 방문 끝났으면 해당 값 리턴. 만약 경로 없으면 10억을 리턴하여 우선순위에서 내려버리기
        return dist[cur][0] ? dist[cur][0] : INF;
    }

    // 메모이제이션
    int &res = dp[cur][visited];    // dp 저장할 주소. 주소로 접근하기 때문에 굳이 배열로 쓸 필요없음
    if(res != -1) {     // 저장 된 값 있으면 그 값 리턴
        return res;
    }

    res = INF;  // 큰 값으로 초기화 하고 최솟값 찾기

    // 로직
    for(int i = 0; i < N; i++) {
        if(visited & (1 << i)) continue;    // 방문한 적 있으면 무시
        if(dist[cur][i] == 0) continue;     // 경로 없으면 무시

        // 주소로 접근해서 dp[cur][visited]에 값 넣는 것과 같은 효과
        res = min(res, tsp(i, visited | (1 << i)) + dist[cur][i]);
    }   // end of for

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> dist[i][j];
        }   // end of for j
    }   // end of for i

    // dp 배열 초기화
    memset(dp, -1, sizeof(dp));     // INF로 안하는 이유는 -1로 할 경우 경로가 없을때 리턴값과 같아서 무한루프에 빠질 수 있음

    cout << tsp(0, 1) << "\n";

    return 0;
}

