#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
#define INF 1e9
using namespace std;

int N, test;
char side, d;
int a[6][20] = {
        {0, 2, 8, 6, 1, 5, 7, 3, 51, 31, 41, 21, 50, 30, 40, 20, 52, 32, 42, 22},
        {10, 12, 18, 16, 11, 15, 17, 13, 56, 26, 46, 36, 57, 27, 47, 37, 58, 28, 48, 38},
        {20, 22, 28, 26, 21, 25, 27, 23, 0, 40, 18, 58, 3, 43, 15, 55, 6, 46, 12, 52},
        {30, 32, 38, 36, 31, 35, 37, 33, 8, 50, 10, 48, 5, 53, 13, 45, 2, 56, 16, 42},
        {40, 42, 48, 46, 41, 45, 47, 43, 6, 30, 16, 28, 7, 33, 17, 25, 8, 36, 18, 22},
        {50, 52, 58, 56, 51, 55, 57, 53, 2, 20, 12, 38, 1, 23, 11, 35, 0, 26, 10, 32}
};
char dir[] = {'U', 'D', 'L', 'R', 'F', 'B'};
char color[] = {'w', 'y', 'g', 'b', 'r', 'o'};
int node[64];
map<char, int> mp;

void rotate_dice() {
    int r = mp[side];
    for(int i = 0; i < 20; i+=4) {
        vector<int> v;
        // 벡터로 따로 분리
        for(int c = i; c < i + 4; c++) {
            v.push_back(node[a[r][c]]);
        }   // end of for

        // 회전
        if(d == '+') rotate(v.begin(), v.end() - 1, v.end());
        else rotate(v.begin(), v.begin() + 1, v.end());

        for(int j = 0; j < 4; j++) {
            node[a[r][i + j]] = v[j]; // 회전 시킨거 입력
        }   // end of for

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 6; i++) {
        mp[dir[i]] = i;
    }

    cin >> test;

    for(int t = 1; t <=test; t++) {
        cin >> N;

        for(int i = 0; i < 60; i++) {
            node[i] = i / 10;
        }

        for(int i = 0; i < N; i++) {
            cin >> side >> d;
            rotate_dice();
        }   // end of for

        for(int i = 0; i < 9; i++) {
            cout << color[node[i]];
            if(i == 2 || i == 5 || i == 8) cout << '\n';
        }
    }   // end of for

}