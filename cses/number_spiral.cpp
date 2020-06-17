#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

#define even(x) ((x) % 2 == 0)
#define odd(x) ((x) % 2 == 1)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t-- > 0)
    {
        ll y, x;
        cin >> y >> x;

        ll ans;
        if (y <= x)
        {
            if (odd(x))
                ans = x * x - y + 1;
            else
                ans = (x-1) * (x-1) + y;
        }
        else
        {
            if (even(y))
                ans = y * y - x + 1;
            else
                ans = (y-1) * (y-1) + x;
        }

        cout << ans << endl;
    }

    return 0;
}

