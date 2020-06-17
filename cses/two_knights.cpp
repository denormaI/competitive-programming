#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    for (ll k = 1; k <= n; k++)
    {
        ll a = ((k * k) * (k * k - 1));
        //ll b = (4 * 2) + (8 * 3) + ((k - 4) * 4 * 4) + (4 * 4) + ((k - 4) * 6 * 4) + (8 * ((k - 4) * (k - 4)));
        ll b = 8 * (k - 2) * (k - 1);
        cout << (a-b) / 2 << endl; 
    } 

    return 0;
}

