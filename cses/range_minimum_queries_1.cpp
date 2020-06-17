#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin >> n >> q;

    ll k = log2(n) + 1;
    vector<vector<ll>> st(n);

    for (int i=0; i<n; i++) {
        ll v;
        cin >> v;
        st[i].resize(k);
        st[i][0] = v;
    }

    for (int j = 1; 1 << j <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            if (st[i][j - 1] < st[i + (1 << (j - 1))][j - 1])
                st[i][j] = st[i][j - 1];
            else
                st[i][j] = st[i + (1 << (j - 1))][j - 1];
        }
    }

    while (q--) {
        ll a,b;
        cin >> a >> b;

        a--; b--;

        int j = (int)log2(b - a + 1); 
  
        if (st[a][j] <= st[b - (1 << j) + 1][j]) 
            cout << st[a][j] << endl; 
        else
            cout << st[b - (1 << j) + 1][j] << endl; 
    } 
}
