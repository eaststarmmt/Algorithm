#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string chair[5];
int res, K, n, d;

int find_left() {
    int left = n;

    // 맞닿는 부분 어디까지 다른지 체크
    for(int i = n - 1; i >= 1; i--) {
        if(chair[left][6] == chair[i][2]) break;    // 만나는 부분이 같으면 종료
        left = i;
    }   // end of for

    return left;
}

int find_right() {
    int right = n;

    // 맞닿는 부분 어디까지 다른지 체크
    for(int i = n + 1; i <= 4; i++) {
        if(chair[right][2] == chair[i][6]) break;    // 만나는 부분이 같으면 종료
        right = i;
    }   // end of for

    return right;
}

void rotate_chair(int dir, int idx) {
    if(dir == 1) {  // 시계방향
        rotate(chair[idx].begin(), chair[idx].end() - 1, chair[idx].end());
    } else {
        rotate(chair[idx].begin(), chair[idx].begin() + 1, chair[idx].end());
    }
}

void turn_left(int left) {
    int dir = -d;
    for(int i = n - 1; i >= left; i--) {
        rotate_chair(dir, i);
        dir *= -1;
    }   // end of for
}

void turn_right(int right) {
    int dir = -d;
    for(int i = n + 1; i <= right; i++) {
        rotate_chair(dir, i);
        dir *= -1;
    }   // end of for
}

void turn() {
    int left = find_left();
    int right = find_right();

    turn_left(left);
    turn_right(right);
    rotate_chair(d, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i <= 4; i++) {
        cin >> chair[i];
    }   // end of for

    cin >> K;

    for(int i = 0; i < K; i++) {
        cin >> n >> d;
        turn();
    }   // end of for

    for(int i = 1, x = 1; i <= 4; i++, x *= 2) {
        if(chair[i][0] == '0') continue;
        res += x;
    }   // end of for

    cout << res << '\n';
    return 0;
}