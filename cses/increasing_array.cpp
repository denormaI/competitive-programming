#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a[200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;
    for (ll i = 1; i < n; i++)
    {
        if (a[i] < a[i-1])
        {
            ll delta = a[i-1] - a[i];
            a[i] += delta;
            ans += delta;
        }
    }

    cout << ans << endl;
}

