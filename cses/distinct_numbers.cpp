#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

set<ll> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        ll v;
        cin >> v;
        a.insert(v);
    }

    cout << a.size() << endl;

    return 0;
}

