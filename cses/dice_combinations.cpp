#include <iostream>
#include <algorithm>
#include <cmath>
#include <array>
#include <cstring>

using namespace std;

typedef long long ll;

ll n;
ll dp[1000001];

// recursive solution. too slow for large n!
ll solve(ll x) {
    if (x == 0) return 1;
    if (x < 0) return 0;
    ll count = 0;
    for (auto d : {1,2,3,4,5,6}) 
        count += solve(x-d);
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    // dp solution
    dp[0] = 1;
    for (int x=1; x<=n; x++) {
        for (auto d : {1,2,3,4,5,6}) {
            if (x-d >= 0) {
                dp[x] += dp[x-d];
                dp[x] %= (ll)(1e9+7);
            }
        }
    }
 
    cout << dp[n] << endl;

    //cout << solve(n) << endl;
}

