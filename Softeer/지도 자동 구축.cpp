#include<iostream>


using namespace std;

int a[20];
int N;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    a[0] = 2;

    for(int i = 1; i <= 15; i++) {
        a[i] = 2 * a[i - 1] - 1;
    }  // end of for

    cout << a[N] * a[N] << '\n';

    return 0;
}