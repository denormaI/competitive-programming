#include <iostream>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// https://discuss.codechef.com/t/coin-piles-problem-from-cses/28647/6



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    /*
        a,b
        x = take 2 from a and 1 from b
        y = take 2 from b and 1 from a

        a = 2x + 1y
        b = 2y + 1x

        2a = 4x + 2y
        2b = 4y + 2x
    
        2a - b = 3x
        2b - a = 3y 
    */

    while (t-- > 0)
    {
        ll a,b;
        cin >> a >> b;
        ll _2ab = 2 * a - b;
        ll _2ba = 2 * b - a;
        if (_2ab >= 0 && _2ab % 3 == 0 &&
            _2ba >= 0 && _2ba % 3 == 0)
           cout << "YES\n";
        else
            cout << "NO\n";
    }
}
