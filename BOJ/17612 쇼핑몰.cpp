#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

typedef long long ll;

struct Cacher {
    int id, max_time, cacher;
};

struct cmp {
    bool operator()(Cacher a, Cacher b) {
        if(a.max_time == b.max_time) return a.cacher > b.cacher;
        return a.max_time > b.max_time;
    }
};

bool cmp2(Cacher a, Cacher b) {
    if(a.max_time == b.max_time) return a.cacher > b.cacher;
    return a.max_time < b.max_time;
}

int N, K;
vector<Cacher> v;
priority_queue<Cacher, vector<Cacher>, cmp> pq;
ll output;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        int id, w;
        cin >> id >> w;

        if(i < K) {     // 계산대 숫자만큼은 그냥 바로 계산대로 가면 됨
            pq.push({id, w, i + 1});
            continue;
        }

        Cacher c = pq.top();    // 제일 빨리 끝나는 계산대
        pq.pop();
        v.push_back(c);
        c.max_time += w;    // 총 기다려야 되는 시간 업데이트
        c.id = id;          // 들어갈 사람 id 변경
        pq.push(c);
    }   // end of for

    while(!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }   // end of while pq

    sort(v.begin(), v.end(), cmp2);

    for(int i = 0; i < v.size(); i++) {
        output += 1ll * (i + 1) * v[i].id;
    }

    cout << output << '\n';
}