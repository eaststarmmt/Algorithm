#include <iostream>
#include <algorithm>

using namespace std;

/*
    M과 N값이 다른 경우 사이클 만큼의 숫자 차이가 발생한다
    ex)
    M N x y -> 10 12 3 9
    x y
    1 1 -> 1 11 -> 1 9 -> 1 7

    위의 예제는 N이 2가 더 크기 때문에 x값 기준으로 사이클을 돌리면 다음번 x값과 만날 때 y값은 2씩 감소하는 것을 볼 수 있다.
    지금부터 dif = M - N 라고 하면
    원하는 x값이 3이므로 (x, y) = (3, 3)으로 이동 한 후에 y값이 9가 나올때까지 y += dif 연산을 하면 답을 찾을 수 있다.
    이때 y += dif 연산에서 y의 최대 범위인 N번의 횟수를 넘으면 무조건 사이클이 발생하게 된다.

    그러므로 이 문제를 맞추는 포인트는
    1. 사이클을 타는 각 값의 규칙 찾기
    2. 회전 구현하기

    이 두가지 요소만 정확히 잡으면 답을 맞힐 수 있다.
 */

int get_pos(int x, int M) {     // 범위 넘어가면 회전 시켜주는 함수
    if(x % M == 0) return M;    // 이 조건이 첫번째 없으면 아래 조건의 엣지케이스로 걸림
    else if(x > M) return x % M;    // dif 값이 넘어오기 때문에 한바퀴가 아닐수도 있음.
    else if(x < 0) return M - (-x % M); // 1 밑으로 떨어지는 경우
    return x;
}

int go(int M, int N, int X, int Y) {
    int res = -1;
    int dif = M - N;    // 두 숫자가 도는 사이클을 이용하기 위함

    // x를 X값에서 시작하기. y만 관찰하기 위함
    int y = get_pos(X, N);  // X가 y값 범위에 들아간 알맞은 값으로 바꾸기
    int start_y = y;    // 사이클을 체크하기 위해 시작 y 값 저장

    if(start_y == Y) return X;  // y값이 X에 도달했을 때 첫 사이클만에 같게 나오면 바로 리턴

    for(int i = 1; i < N; i++) {    // x를 그대로 둔 채 y 값만 돌리므로 최대 N번의 사이클이 돌게 됨
        y = get_pos(y + dif, N);   // y 값은 M 과 N 의 차이만큼 변화함

        if(y == Y) {    // 원하는 값에 도달한 경우
            res = i * M + X;    // 사이클 횟수(i) * X 사이클의 길이(M) + 시작위치까지 가는 값(X)
            break;
        } else if(y == start_y) {     // 초기 위치로 돌아온 경우. if문과 순서 바뀌면 시작 위치가 답인 경우에 문제 발생
            break;
        }
    }   // end of for
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0 ; i < T; i++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << go(M, N, x, y) << '\n';
    }

    return 0;
}