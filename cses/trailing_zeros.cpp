#include <iostream>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll z = 0;

    for (int i = 5; n / i >= 1; i *= 5)
        z += n / i;

    cout << z << endl;
}
