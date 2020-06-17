#include <iostream>

using namespace std;

typedef long long ll;

ll modpow(ll base, ll exp, ll mod) {
    base %= mod;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;   
    
    while (n-- > 0) {
        ll a,b;
        cin >> a >> b;
        cout << modpow(a,b,(ll)1e9+7) << endl;
    }
}
