#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll a[201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    for (int test=1; test<=t; test++) {
        ll n;
        cin >> n;

        ll ans = 0;
        for (int i=0; i<n; i++)
            cin >> a[i];

        for (int i=0; i<n; i++)
            if (i != 0 && i != n-1)
                if (a[i] > a[i-1] && a[i] > a[i+1])
                    ans++;
    
        cout << "Case #" << test << ": " << ans << endl;
    }
}
