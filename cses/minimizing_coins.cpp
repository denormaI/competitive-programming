#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

#define inf ((ll)1e9)

typedef long long ll;

ll dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,x;
    cin >> n >> x;

    vector<ll> a;
    for (int i=0; i<n; i++) {
        ll t;
        cin >> t;
        a.push_back(t);
    }

    sort(a.begin(), a.end());
    
    // dp solution
    dp[0] = 0;
    for (int i=1; i<=x; i++) {
        dp[i] = inf;
        for (auto c : a) {
            if (i-c >= 0)
                dp[i] = min(dp[i], dp[i-c]+1);
        }
    }
 
    cout << (dp[x] == inf ? -1 : dp[x]) << endl;
}

