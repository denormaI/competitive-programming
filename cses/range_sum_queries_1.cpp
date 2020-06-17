#include <iostream>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll a[(ll)(2*1e5+1)];
ll sum[(ll)(2*1e5+2)];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin >> n >> q;

    for (int i=0; i<n; i++)
        cin >> a[i];

    sum[0] = 0;
    for (int i=1; i<=n; i++)
        sum[i] = sum[i-1] + a[i-1];

    while (q-- > 0) {
        ll a,b;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << endl;
    } 
}
