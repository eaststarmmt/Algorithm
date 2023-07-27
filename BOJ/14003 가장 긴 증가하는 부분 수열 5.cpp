#include<iostream>
#include<algorithm>
#include<stack>
#define INF -1000000004
using namespace std;

int lis[1000004];   // LIS 값 저장할 배열
pair<int, int> res[1000004];    // 각각 값들이 몇번째 원소로 들어가는지 확인할 배열
int N, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    fill(lis, lis + N, INF);

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        int idx = lower_bound(lis, lis + cnt, num) - lis;

        if(lis[idx] == INF) {     // 해당 인덱스의 값이 0이면 lis 개수 카운팅
            cnt++;
        }

        lis[idx] = num;
        res[i].first = idx;     // i 번째 숫자가 lis에서 들어갈 인덱스 저장
        res[i].second = num;    // i 번째 숫자의 값 저장

    }   //end of for

    cout << cnt << "\n";
    // 스택에 넣어서 출력값 새로 뽑아야 되는 이유는 마지막에 작은 값 들어갔으면 lis에 들어있는 값과 실제 lis가 다를수 있음
    // res 기반으로 출력해야됨
    stack<int> stk;

    for(int i = N - 1; i >= 0; i--) {
        int idx = res[i].first;
        int num = res[i].second;
        if(cnt - 1 == idx) {    // cnt는 개수 idx는 인덱스이므로 -1 해줘야 됨
            stk.push(num);
            idx--;
            cnt--;
        }
    }   // end of for

    while(!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    cout << "\n";

    return 0;
}

/*
8
1 6 2 5 7 3 5 6

5
3 1 3 4 -1
*/