#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, res, x, dif = 1e9;
vector<int> v;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for(int i = 1; i < N; i++) {
        if(v[i] - v[i - 1] < dif) {
            dif = v[i] - v[i - 1];
            res = 1;
        } else if(v[i] - v[i - 1] == dif) res++;
    }

    cout << res << '\n';
    return 0;
}