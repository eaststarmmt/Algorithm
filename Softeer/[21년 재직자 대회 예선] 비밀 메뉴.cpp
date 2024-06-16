#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int N, M, K;
string a, secret;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;
    cin.ignore();  // cin 버퍼에 개행문자 들어있어서 버퍼 비워줘야 됨
    getline(cin, secret);
    getline(cin, a);

    if(a.find(secret) == string::npos) cout << "normal\n";
    else cout << "secret\n";

    return 0;
}