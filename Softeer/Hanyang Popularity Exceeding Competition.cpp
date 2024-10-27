#include<iostream>
#include<cmath>

using namespace std;

int N, X;
int P[200004], C[200004];

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> P[i] >> C[i];
    }

    for(int i = 0; i < N; i++) {
        if(abs(P[i] - X) > C[i]) continue;
        X++;
    }

    cout << X << '\n';
}