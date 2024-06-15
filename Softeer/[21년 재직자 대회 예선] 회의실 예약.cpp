#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int N, M, s, t;
string r;
vector<pair<int,int>> graph[50];
int reservation[50][19];          // 회의실 인덱스, 시간
string room[50];
map<string, int> m;

void mark() {
    int idx = m[r];
    for(int i = s; i < t; i++) {
        reservation[idx][i]++;
    }    // end of for
    if(t == 18)
        reservation[idx][t]++;
}

void print(int idx) {
    if(idx) cout << "-----\n";
    cout << "Room " << room[idx] << ":\n";
    vector<string> v;
    int start = 0;
    for(int i = 9; i <= 18; i++) {
        if(reservation[idx][i] && start) {  // 예약 되어 있고 비어있는 시간 측정하고 있던 경우 저장
            string start_time = "0" + to_string(start);
            v.push_back((start_time.substr(start_time.size() - 2)) + '-' + to_string(i));
            start = 0; // 다음 시간 측정을 위해 초기화
        }
        else if(reservation[idx][i]) continue;  // 예약중인 경우 무시. 더 이상 예약 조건을 고려하지 않기 위한 추가 조건. 밑에 조건부터는 다 false
        else if(!start) start = i;  // 시작점이 없는 경우 시작점 갱신
    }  // end of for
    if(start) {  // for문이 끝나는 바람에 18시까지 가능한 경우 벡터에 저장이 안된 경우
        string start_time = "0" + to_string(start);
        v.push_back((start_time.substr(start_time.size() - 2)) + '-' + to_string(18));
    }

    if(v.empty()) {
        cout << "Not available\n";
        return;
    }

    cout << v.size() << " available:\n";
    for(string time : v) {
        cout << time << '\n';
    }  // end of for
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> r;
        room[i] = r;
    }    // end of for

    sort(room, room + N);

    for(int i = 0; i < N; i++) {  // 회의실 이름에 매핑 된 인덱스 저장
        m[room[i]] = i;
    }

    for(int i = 0; i < M; i++) {
        cin >> r >> s >> t;
        mark();
    }    // end of for

    for(int i = 0; i < N; i++) {
        print(i);
    }

    return 0;
}