#include<iostream>


using namespace std;

int a[8];
bool asc, des;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 8; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < 8; i++) {
        if(a[i] > a[i - 1]) asc = true;
        else des = true;
    }

    if(asc && des) cout << "mixed" << '\n';
    else if(asc) cout << "ascending" << '\n';
    else cout << "descending" << '\n';

    return 0;
}