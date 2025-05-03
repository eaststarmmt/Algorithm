#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define INF 1e9

using namespace std;

int R, C, T, D, output;
int a[30][30], graph[3000][3000];
vector<int> pos;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    scanf("%d %d %d %d", &R, &C, &T, &D);

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            char c;
            scanf(" %c", &c); // 공백을 주어 개행문자 무시
            if(c <= 'Z') a[i][j] = c - 'A';
            else a[i][j] = c - 'a' + 26;
        }   // end of for C
    }   // end of for R

    fill(&graph[0][0], &graph[0][0] + 3000 * 3000, INF);

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            pos.push_back(i * 100 + j); // 2차원 배열을 1차원으로 만든 좌표들 값 미리 저장. 안그러면 나중에 for문 쓸때 너무 커짐
        }   // end of for C
    }   // end of for R

    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            for(int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                int dif = abs(a[nr][nc] - a[r][c]);

                if(dif > T) continue;   // 높이 차이 T보다 큰 경우는 이동 불가

                int cur = r * 100 + c;
                int next = nr * 100 + nc;

                if(a[nr][nc] > a[r][c]) {   // 높은곳으로 이동할 때
                    graph[cur][next] = dif * dif;
                } else {                    // 낮거나 같은 높이
                    graph[cur][next] = 1;
                }
            }   // end of for dir
        }   // end of for C
    }   // end of for R

    // 플로이드 워셜
    for(int k : pos) {
        for(int j : pos) {
            for(int i : pos) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }   // end of for i
        }   // end of for j
    }   // end of for k

    output = a[0][0];

    for(int i : pos) {
        int cost = graph[0][i] + graph[i][0];
        if(cost > D) continue;  // 산에 갔다 호텔까지 오는 시간이 D를 넘어가면 무시
        output = max(a[i / 100][i % 100], output);  // 갈 수 있는 곳 중 높이가 가장 높은곳을 선택
    }   // end of for pos

    printf("%d\n", output);

}