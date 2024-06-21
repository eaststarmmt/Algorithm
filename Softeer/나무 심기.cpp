#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, res, x;
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

    res = max(v[0] * v[1], v[v.size() - 1] * v[v.size() - 2]);

    cout << res << '\n';
    return 0;
}