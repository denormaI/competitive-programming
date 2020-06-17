#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> nv;
    nv.reserve(n);
    for (ll i = 1; i <= n; i++)
        if (i % 2 == 0)
            nv.push_back(i);

    for (ll i = 1; i <= n; i++)
        if (i % 2 == 1)
            nv.push_back(i);

    for (ll i = 1; i < n; i++)
    {
        if (abs(nv[i] - nv[i-1]) == 1)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

     for (auto& e : nv)
        cout << e << " ";
    cout << endl;   

    return 0;
}

