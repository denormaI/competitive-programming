#include <iostream>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll a[(ll)(1.5*1e5)];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin >> n >> k;

    for (int i=0; i<n; i++)
        cin >> a[i];

    ll ksum = 0;
    for (int i=0; i<k; i++)
        ksum += a[i];

    ll m=(ll)1e9, ans=1;

    m = min(m,ksum);

    for (int i=1,j=k; j<n; i++,j++) {
        ksum -= a[i];
        ksum += a[j];
        if (m < ksum) {
            m = ksum;
            ans = i+1;
        }
    }

    cout << ans << endl;
}

